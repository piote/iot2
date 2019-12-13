int swCount = 0;   //스위치 동작 횟수 저장용 변수

int ledRed = 8;    // 
int ledGreen = 9;
int ledBlue = 10;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  Serial.begin(9600); //통신속도 9600으로 하드웨어 시리얼 초기화
  
  //Serial 포트가 준비될 때까지 대기
  while (!Serial) // Seiral port가 준비되지 않았으면
    ;             // 하는 일 없이 대기.(준비되면 while 종료)
  Serial.println("시리얼 통신 준비 완료!"); //PC에 통신준비 되었음을 알림.
}

void serialEvent() {
  int inChar;
  if (Serial.available() > 0) {
    inChar = Serial.read();

    if (inChar == 'R')
        toggleLED(ledRed);
    else if (inChar == 'G')
        toggleLED(ledGreen);
    else if (inChar == 'B')
        toggleLED(ledBlue);
    else if (inChar == ' ')
        delay(300);
  }
}
void toggleLED(int ledPin) {
  if (digitalRead(ledPin) == HIGH)
    digitalWrite(ledPin, LOW);
  else
    digitalWrite(ledPin, HIGH);
}
void loop() {
  if (digitalRead(swInput) == HIGH) { //스위치가 눌러졌으면
    swCount = swCount + 1;  // 누른 횟수 1 증가
    Serial.print("스위치 누른 횟수: ");
    Serial.println(swCount);  //swCount 값 전송
    delay(300); // delay(300)을 생략한 경우 동작 확인.
  }
}
