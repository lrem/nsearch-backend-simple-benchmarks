#-*- coding: utf-8 -*-

import asyncio
from aiohttp import web

async def hello(request):
    return web.json_response({'hello': 'world!'})

app = web.Application()
app.router.add_route('GET', '/', hello)
web.run_app(app)
