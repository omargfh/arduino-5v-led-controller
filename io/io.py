from arduino import connect
from server import startServer

def main():
    arduino = connect()
    startServer(arduino)

if __name__ == "__main__":
    main()