//Project: SOS Button v2.0
//Board: TTGO T-Call v1.3 with SIM800L
//License GNU General Public License (GPL) v3
//Copy: (C) 2020 by Dawid Irzyk

#define SIM800L_RX     27
#define SIM800L_TX     26
#define SIM800L_PWRKEY 4
#define SIM800L_RST    5
#define SIM800L_POWER  23

int touchPin = 22;
int val = 0;
int relayPin = 13;

void setup()
{
  pinMode(SIM800L_POWER, OUTPUT);
  digitalWrite(SIM800L_POWER, HIGH);
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, SIM800L_TX, SIM800L_RX);
  delay(1000);
  Serial.println("");
  Serial.println("--- Loading Firmware v2.0 ---\n");
  delay(5000);
  Serial.println("--- SOS Button v2.0 ---");
  Serial.println("--- AT command SIM800L ---");
  Serial.println("--- (C) 2020 by Dawid Irzyk ---");
  Serial.println("");
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}

void loop() {
  digitalWrite(relayPin, HIGH);
  val = digitalRead(touchPin);
  if (val == 1) {
    Serial.println("Starting program...\n");
     for(int i=2; i>0; i--){
      //First phone number      
      Send_AT("ATD+48XXXXXXXXX;");
      delay(12000);
      Send_AT("ATH");
      delay(4000);
      //Second phone number
      Send_AT("ATD+48XXXXXXXXX;");
      delay(12000);
      Send_AT("ATH");      
    }
    Serial.println("Program completed...\n");
  }
}

void Send_AT(String command) {
  Serial.println("AT: " + command);
  Serial2.println(command);
  long timer = millis();
  while (timer + 3000 > millis()) {
    while (Serial2.available()) {
      Serial.write(Serial2.read());
    }
  }
  Serial.println();
}
