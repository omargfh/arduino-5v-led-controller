from flask import Blueprint, request, jsonify
import io.led as led

def defineGlobalVars(arduino):
    global vars
    vars = {
        "arduino": arduino
    }

def route():
    hex = request.args.get("hex")
    command = led.hexToCommand(hex)
    vars["arduino"].send(command)
    return jsonify({"status": "ok"})