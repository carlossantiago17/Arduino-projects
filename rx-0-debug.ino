// This is the code to recieve data from another arduino using RX and TX

int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}
int count = 0;
void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
               // Serial.print("I received: ");
                Serial.print(incomingByte, DEC);
                Serial.print(" ");
                if (count % 20 == 0)Serial.println();
                count++;
                if (count > 1000)count = 0;
        }
}
