#include <Ethernet.h>
#include <Servo.h>

// Create a Servo object
Servo servo;

// Ethernet server
EthernetServer server(9000);

void setup() {
  // Start the Ethernet server
  server.begin();

  // Attach the servo to a digital pin
  servo.attach(7);
}

void loop() {
  // Check if there are any incoming TCP connections
  EthernetClient client = server.available();
  if (client) {
    // Read the incoming command as a single byte
    int command = client.read();

    // Check if the angle is within the acceptable range
    if (command >= 0 && command <= 180) {
      // Set the servo angle
      servo.write(command);
    }
  }
}
