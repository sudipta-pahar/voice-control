int m1 = 4;
int m2 = 5;
int m3 = 6;
int m4 = 9;

char value ;
String a;
int i = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}

void forward()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}
void backward()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
void left()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
void right()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void stop1()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void loop()
{
  while (Serial.available())
  {
    value = Serial.read();
    a += value;


    Serial.print("Value is: ");
    Serial.println(String (value));
    delay(100);

  }
  i = 0;
  Serial.println(a);



  if (a == "forward")
  {
    forward();
    a = "";
  }
  else if (a == "backward")
  {
    backward();
    a = "";
  }
  else if (a == "right")
  {
    left();
    a = "";
  }
  else if (a == "left")
  {
    right();
    a = "";
  }
  else if (a == "stop")
  {
    stop1();
    a = "";
  }
  else
  {
    a = "";

  }
  delay(100);
}
