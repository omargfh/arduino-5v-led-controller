from time import sleep
from flask import Flask, request, jsonify
from flask_cors import CORS
import routes
import math

arduino = None
app = Flask(__name__)
CORS(app)


def startServer(local_arduino = None):
    global arduino
    arduino = local_arduino

    routes.defineRoutes(app, arduino)
    app.run(host='0.0.0.0', port=8080)
