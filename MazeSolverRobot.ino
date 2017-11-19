/*

  @Author Swornim Shrestha(swornim00)
  @Author Email srestaswrnm@gmail.com

*/

/*
  Here we are assigning pins to some variables
*/
int left_1= 13;
int left_2= 12;
int center= 11;
int right_1= 10;
int right_2= 9;

int motor_left_fwd =8;
int motor_left_bckwd=7;
int motor_right_bckwd=6;
int motor_right_fwd= 5;

void setup() {
  /*
     Here we are decalring pin mode for the pins that we defined before
  
  */
  pinMode(left_1, INPUT);
  pinMode(left_2, INPUT);
  pinMode(center, INPUT);
  pinMode(right_1, INPUT);
  pinMode(right_2, INPUT);
  pinMode(motor_left_fwd, OUTPUT);
  pinMode(motor_left_bckwd, OUTPUT);
  pinMode(motor_right_bckwd, OUTPUT);
  pinMode(motor_right_fwd, OUTPUT);
  
  Serial.begin(9600); // Starting Serial Communication at Baud rate of 9600

}

/*
  [*] Here we are going to implement Left Hand Rule Algorithm to help 
      the robot solve the maze.
*/
void loop() {

   
}
