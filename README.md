# TTGO-T-Call-1.3-SOS-Button

Project: SOS Button v2.0<br>
Board: TTGO T-Call v1.3 with SIM800L<br>
License GNU General Public License (GPL) v3<br>
Copy: (C) 2020 by Dawid Irzyk

<b>Application example:</b><br>
<em>We use it to call for help, e.g. in an epilepsy attack, to call in household members on their phone if they are nearby.</em><br>

At <b>Send_AT("ATD+48XXXXXXXXX;");</b>, enter your phone number.
<br><br>
+48 is the area code for Poland<br>
Please change it to the code for your country.<br>
TTGO T-Call 1.3 calls each number twice.
<br><br>
<b>The code is for the Arduino IDE</b>
<br>

Connect TTP223 to TTGO T-Call 1.3<br>
VCC to 5V<br>
GND to GND<br>
OUT to 22 PIN
