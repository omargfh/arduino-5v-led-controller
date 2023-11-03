import index
import setRGB

routes = {
    "/": index,
    "/setRGB": setRGB
}
def defineRoutes(app, arduino):
    for (path, route) in routes.items():
        route.defineGlobalVars(arduino)
        app.add_url_rule(path, path, route.route)