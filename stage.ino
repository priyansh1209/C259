#include <Keypad.h>

#define row_num     4 // four rows
#define col_num  4 // four columns

String password = "111111";
String input = "";

char keys[row_num][col_num] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte row_pins[row_num]      = {19, 18, 5, 17}; // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
byte col_pins[col_num] = {16, 4, 2, 15};   // GIOP16, GIOP4, GIOP0, GIOP2 connect to the column pins

Keypad keypad = Keypad( makeKeymap(keys), row_pins, col_pins, row_num, col_num);

void setup() {
  Serial.begin(115200);
  Serial.print("Enter password : ");
}

void loop() {

  //  getkey method returns a character
  char key = keypad.getKey();

  if (key)
  {
    //  if '#' pressed , check password
    if (key  ==  '#'){

      Serial.println();

      if (input.compareTo(password)  ==  0){
        Serial.println("Access granted, welcome !");
        while(true);
      }

      else{
        Serial.println("Access denied!");
        Serial.print("Try again : ");
      }

      //  clear the input string
      input = "";
    }

    else if (key  ==  '*'){

      //  clear the input string
      input = "";
      Serial.println();
      Serial.print("Password cleared, enter again : ");

    }

    else{

      //  adding character to input string
      input.concat(key);
      Serial.print(key);
    }
  }
}
