int buttonState_1 = 0;
int buttonState_2 = 0;
int button_1 = 1;
int button_2 = 2;
void setup(){
pinMode(button_1, INPUT);
pinMode(button_2, INPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
}
void loop() {
buttonState_1 = digitalRead(button_1);
buttonState_2 = digitalRead(button_2);
combination_1();
combination_2();
combination_3();
combination_4();
}
void combination_1(){
if (buttonState_1 == LOW && buttonState_2 == LOW){
digitalWrite(13, HIGH);
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);
digitalWrite(10, HIGH);
digitalWrite(9, HIGH);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
digitalWrite(6, HIGH);
}
}
void combination_2(){
if (buttonState_1 == LOW && buttonState_2 == HIGH){
digitalWrite(13, HIGH);
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
}
}
void combination_3(){
if (buttonState_1 == HIGH && buttonState_2 == LOW){
digitalWrite(13, LOW);
digitalWrite(12,LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
digitalWrite(6, HIGH);
}
}
void combination_4(){
if (buttonState_1 == HIGH && buttonState_2 == HIGH){
digitalWrite(13, LOW);
digitalWrite(12,LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
digitalWrite(9, LOW);
digitalWrite(8,LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
}
}
