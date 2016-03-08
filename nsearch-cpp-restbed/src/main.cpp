#include <memory>
#include <cstdlib>
#include <restbed>
#include "json/json.h"

using namespace std;
using namespace restbed;

void get_method_handler( const shared_ptr< Session > session )
{
    const auto request = session->get_request( );

    int content_length = 0;
    request->get_header( "Content-Length", content_length );

    session->fetch( content_length, [ ]( const shared_ptr< Session > session, const Bytes & body )
    {
        Json::Value root;
        root["hello"] = "world!";

        Json::FastWriter fastWriter;
        std::string output = fastWriter.write(root);
        std::string contentLength = std::to_string(output.length());
        session->close( OK, output, { { "Content-Length", contentLength }, { "Content-type", "application/json" } } );
    } );
}

int main( const int, const char** )
{
    auto resource = make_shared< Resource >( );
    resource->set_path( "/" );
    resource->set_method_handler( "GET", get_method_handler );

    auto settings = make_shared< Settings >( );
    settings->set_port( 8080 );
    settings->set_default_header( "Connection", "close" );

    Service service;
    service.publish( resource );
    service.start( settings );
}
