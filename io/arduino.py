import serial.tools.list_ports

arduino = None
def connect(default = None):
    ports = list(serial.tools.list_ports.comports())
    serialInst = serial.Serial()

    _ = [print(f"{i}. {port}") for i, port in enumerate(ports)]
    print("Enter the port number: ", end="")
    try:
        port_number = default if default else int(input())
        print(f"Selected port: {port_number}")
        port = ports[port_number]
    except:
        print("Invalid port number!")
        exit()

    serialInst.baudrate = 115200
    serialInst.port = port.device
    serialInst.open()

    print("Connected to Arduino!")

    global arduino
    arduino = {
        "serial": serialInst,
        "send": send
    }
    return arduino

def send(command):
    arduino['serial'].write(command.to_bytes(8, byteorder='little'))