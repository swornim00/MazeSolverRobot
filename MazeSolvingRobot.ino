/*

  @Author Swornim Shrestha(swornim00)
  @Author Email srestaswrnm@gmail.com

*/

/*
  Here we are assigning pins to some variables
*/
int left_1 = 6;
int left_2 = 7;
int center = 5;
int right_1 = 2;
int right_2 = 3;

int motor_left_fwd = 10;
int motor_left_bckwd = 11;
int motor_right_bckwd = 9;
int motor_right_fwd = 8;
char steps[] = {};
char sfl[] = {}; // sfl = Save from loops
int sfl_count = 0;
int step_count = 0;
int leapTime = 200;

int l1_s;
int l2_s;
int c_s;
int r1_s;
int r2_s;

void done();
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

      Edited : Nov 24, 2017 5:35 PM
        [*] But with left hand rule, the robot seem to be stucked in a loop and I modified the algorithm to use prevent it from being stucked in a loop
*/

void loop() {

  for(i = 0; i != sfl_count ; i++){
    
  }
  readValues();
  if(!l2_s && c_s && !r2_s){
    straight();  
  }else{
    LeftHandRuleModified();
  }
  delay(1000);
}

void readValues(){
  l1_s = digitalRead(left_1);
  l2_s = digitalRead(left_2);
  c_s = digitalRead(center);
  r2_s = digitalRead(right_2);
  r1_s = digitalRead(right_1);
}

void LeftHandRuleModified(){ // Modified Left Hand Algorithm to save bot from loops
  readValues();
  if(l2_s && l1_s && c_s && r1_s && r2_s){
    digitalWrite(motor_left_fwd, HIGH);
    digitalWrite(motor_left_bckwd, LOW);
    digitalWrite(motor_right_fwd, HIGH);
    digitalWrite(motor_right_bckwd, LOW);
    delay(leapTime);

    if(l2_s && l1_s){
      done();
    }else{
      turnLeft();
    }
  }

  if(l2_s && l1_s && c_s && !r1_s & !r2_s){
    if(l2_s && l1_s){
      done();
    }else{
      turnLeft();
    }
  }
    if(!l2_s && !l1_s && c_s && r1_s & r2_s){
    if(l2_s && l1_s){
      done();
    }else{
      turnRight();
    }
  }
  
  
  
  
  
  if(l2_s && r2_s){
      
  }
  if(l2_s && r2_s){ // End point aayo
     
  }
  if(!l2_s || !r2_s ){
    
      if(l2_s && l1_s && c_s){
        turnLeft();
      }
  }
}


void straight(){
  
  digitalWrite(motor_left_fwd, HIGH);
  digitalWrite(motor_left_bckwd, LOW);
  digitalWrite(motor_right_fwd, HIGH);
  digitalWrite(motor_right_bckwd, LOW);
  delay(20);
  readValue();
  if(c_s){
    turnAround(); // End Point Reached
  }
}

void turnLeft(){
  digitalWrite(motor_left_fwd, LOW);
  digitalWrite(motor_left_bckwd, LOW);
  digitalWrite(motor_right_fwd, HIGH);
  digitalWrite(motor_right_bckwd, LOW);
  sfl[sfl_count] += 'L';
  sfl_count += 1;
}

void turnRight(){
  digitalWrite(motor_left_fwd, LOW);
  digitalWrite(motor_left_bckwd, LOW);
  digitalWrite(motor_right_fwd, HIGH);
  digitalWrite(motor_right_bckwd, LOW);
  sfl[sfl_count] += 'R';
  sfl_count += 1;
} 

void turnAround(){
  digitalWrite(motor_left_fwd, LOW);
  digitalWrite(motor_left_bckwd, HIGH);
  digitalWrite(motor_right_fwd, HIGH);
  digitalWrite(motor_right_bckwd, LOW);
  delay(leapTime);
  straight();
  sfl[sfl_count] += 'B';
  sfl_count += 1;
}

void done(){
  digitalWrite(motor_left_fwd, LOW);
  digitalWrite(motor_left_bckwd, LOW);
  digitalWrite(motor_right_fwd, LOW);
  digitalWrite(motor_right_bckwd, LOW);
}


