from flask import Flask, request, jsonify

vars = {}
def route():
    return jsonify({"status": "ok", "arduino": "connected" if vars['arduino'] else "disconnected"})

def defineGlobalVars(arduino):
    global vars
    vars = {
        "arduino": arduino
    }