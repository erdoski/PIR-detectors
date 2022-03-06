long nextCheck;
int dataPin1 = 2, dataPin2 = 3, dataPin3 = 4, dataPin4 = 5, dataPin5 = 6;
int led1 = 8, led2 = 9, led3 = 10, led4 = 11, led5 = 12;
int variable;
int sn,sn1,sn2,sn3,sn4;
int waitTime = 10;

 //255 205 175 100 20
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(dataPin1,INPUT);
  pinMode(dataPin2,INPUT);
  pinMode(dataPin3,INPUT);
  pinMode(dataPin4,INPUT);
  pinMode(dataPin5,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(HIGH){
    bool trigger1 = digitalRead(dataPin1);
    bool trigger2 = digitalRead(dataPin2);
    bool trigger3 = digitalRead(dataPin3);
    bool trigger4 = digitalRead(dataPin4);
    bool trigger5 = digitalRead(dataPin5);
    if((trigger1 && trigger2) || (trigger1 && trigger3) ||
       (trigger1 && trigger4) || (trigger1 && trigger5) || 
       (trigger2 && trigger3) || (trigger2 && trigger4) || 
       (trigger2 && trigger5) || (trigger3 && trigger4) || 
       (trigger3 && trigger5) || (trigger4 && trigger5)){
      Serial.println("Triggered: Initilizng case 6 (" + String(millis()) + ")");
      nextCheck = millis() + 3000;
      Serial.println("Next Check: " + String(nextCheck));
      variable = 6;
    }  else if(trigger5){
      Serial.println("Triggered Initilizng case 5 (" + String(millis()) + ")");
      nextCheck = millis() + 3000;
      Serial.println("Next Check: " + String(nextCheck));
      variable = 5;
    } else if(trigger2){
      Serial.println("Triggered Initilizng case 2 (" + String(millis()) + ")");
      nextCheck = millis() + 3000;
      Serial.println("Next Check: " + String(nextCheck));
      variable = 2; 
    } else if(trigger3){
      Serial.println("Triggered Initilizng case 3 (" + String(millis()) + ")");
      nextCheck = millis() + 3000;
      Serial.println("Next Check: " + String(nextCheck));
      variable = 3; 
    } else if(trigger4){
      Serial.println("Triggered Initilizng case 4 (" + String(millis()) + ")");
      nextCheck = millis() + 3000;
      Serial.println("Next Check: " + String(nextCheck));
      variable = 4; 
    } else if(trigger1) {
      Serial.println("Triggered Initilizng case 1 (" + String(millis()) + ")");
      nextCheck = millis() + 3000;
      Serial.println("Next Check: " + String(nextCheck));
      variable = 1;       
    } else {
      analogWrite(led1,0);
      analogWrite(led2,0);
      analogWrite(led3,0); 
      analogWrite(led4,0); 
      analogWrite(led5,0);
      variable = 0;
    }
    
    //Serial.println(variable);
    switch(variable){
    case 1 :
      sn = 0;
      while(sn < waitTime){
        analogWrite(led1,255); delay(400);
        analogWrite(led2,225); delay(400);
        analogWrite(led3,100); delay(400);
        analogWrite(led4,20); 
        sn = sn + 1;
        Serial.println(" sn'nin değeri:" + String(sn));
        delay(100);
        bool trigger2 = digitalRead(dataPin2);
        bool trigger3 = digitalRead(dataPin3);
        bool trigger4 = digitalRead(dataPin4);
        bool trigger5 = digitalRead(dataPin5);
        
        if(trigger2){
          sn = 10;
          sn1 = 0;
          while(sn1 < waitTime){
            analogWrite(led1,175);
            analogWrite(led2,255);
            analogWrite(led3,205); 
            analogWrite(led4,100); 
            analogWrite(led5,20);
            sn1 = sn1 + 1; 
            Serial.println(" sn1'nin değeri:" + String(sn1));
            delay(1000);
            bool trigger3 = digitalRead(dataPin3);
            bool trigger1 = digitalRead(dataPin1);
            bool trigger4 = digitalRead(dataPin4);
            bool trigger5 = digitalRead(dataPin5);
            
            if(trigger3) {  
              sn1 = 10;
              sn2 = 0;
              while(sn2 < waitTime){
                analogWrite(led1,0);
                analogWrite(led2,175);
                analogWrite(led3,255); 
                analogWrite(led4,205); 
                analogWrite(led5,100);
                sn2 = sn2 + 1;
                Serial.println(" sn2'nin değeri:" + String(sn2));
                delay(1000);
                bool trigger1 = digitalRead(dataPin1);
                bool trigger2 = digitalRead(dataPin2);
                bool trigger4 = digitalRead(dataPin4);
                bool trigger5 = digitalRead(dataPin5);

                if(trigger4){
                  sn2 = 10;
                  sn3 = 0;
                  while(sn3 < waitTime) {
                    analogWrite(led2,0);
                    analogWrite(led3,205); 
                    analogWrite(led4,255); 
                    analogWrite(led5,205);
                    sn3 = sn3 + 1;
                    Serial.println(" sn3'nin değeri:" + String(sn3));
                    delay(1000);
                    bool trigger1 = digitalRead(dataPin1);
                    bool trigger2 = digitalRead(dataPin2);
                    bool trigger3 = digitalRead(dataPin3);
                    bool trigger5 = digitalRead(dataPin5);

                    if(trigger5){
                      sn3 = 10;
                      sn4 = 0;
                      while (sn4 < (waitTime-1)){
                          analogWrite(led3,0); 
                          analogWrite(led4,205); 
                          analogWrite(led5,255);
                          sn4 = sn4 + 1;
                          Serial.println(" sn4'nin değeri:" + String(sn4));
                          delay(1000);
                          bool trigger1 = digitalRead(dataPin1);
                          bool trigger2 = digitalRead(dataPin2);
                          bool trigger3 = digitalRead(dataPin3);
                          bool trigger4 = digitalRead(dataPin4);
                          if(trigger1 || trigger2 || trigger3 || trigger4 ){
                            Serial.println("Pathway5 bozuldu");
                            break;
                        }
                      }
                      analogWrite(led4,0); delay(500);
                      analogWrite(led5,0); 
                    } if(trigger1 || trigger2 || trigger3 ){
                        Serial.println("Pathway4 bozuldu");
                        break;
                    }
                  }
                } if(trigger1 || trigger2 || trigger5 ){
                  Serial.println("Pathway bozuldu");
                  break;
                }
              }
            } if(trigger1 || trigger4 || trigger5){
              Serial.println("Pathway bozuldu");
              break; 
            }
           }
        } if(trigger3 || trigger4 || trigger5){
            Serial.println("Pathway bozuldu");
            break;
       }
    }
    if((sn == waitTime) && (sn1 == 0) && (sn2 == 0) && (sn3 == 0) && (sn4 == 0)){
      analogWrite(led4,0); delay(300);
      analogWrite(led3,0); delay(300);
      analogWrite(led2,0);  delay(300);
      analogWrite(led1,0); 
      analogWrite(led5,0);
    }
    break;
    
    case 0 :
      digitalWrite(led1,LOW);
      break;
      
    case 2:
      sn = 0;
      while(sn < waitTime){
        analogWrite(led1,150);
        analogWrite(led2,255);
        analogWrite(led3,150); 
        analogWrite(led4,0); 
        analogWrite(led5,0);
        sn = sn + 1;
        delay(1000);
        Serial.println(" sn'nin değeri:" + String(sn));
        bool trigger5 = digitalRead(dataPin4);
        bool trigger4 = digitalRead(dataPin3);
        bool trigger3 = digitalRead(dataPin2);
        bool trigger1 = digitalRead(dataPin1);
        if(trigger1 || trigger3 || trigger4 || trigger5){
          Serial.println("case 2'den çıkıldı");
          break;
        }
      }
      break;
    case 3:
      sn = 0;
      while(sn < waitTime){
        analogWrite(led1,0);
        analogWrite(led2,150);
        analogWrite(led3,255); 
        analogWrite(led4,150); 
        analogWrite(led5,0);
        sn = sn + 1;
        delay(1000);
        Serial.println(" sn'nin değeri:" + String(sn));
        bool trigger5 = digitalRead(dataPin4);
        bool trigger4 = digitalRead(dataPin3);
        bool trigger2 = digitalRead(dataPin2);
        bool trigger1 = digitalRead(dataPin1);
        if(trigger1 || trigger2 || trigger4 || trigger5){
          Serial.println("case 2'den çıkıldı");
          break;
        }
      }
      break;
    case 4:
      sn = 0;
      while(sn < waitTime){
        analogWrite(led5,150);
        analogWrite(led4,255);
        analogWrite(led3,150); 
        analogWrite(led2,0); 
        analogWrite(led1,0);
        sn = sn + 1;
        delay(1000);
        Serial.println(" sn'nin değeri:" + String(sn));
        bool trigger5 = digitalRead(dataPin5);
        bool trigger3 = digitalRead(dataPin3);
        bool trigger2 = digitalRead(dataPin2);
        bool trigger1 = digitalRead(dataPin1);
        if(trigger1 || trigger2 || trigger3 || trigger5){
          Serial.println("case 4'den çıkıldı");
          break;
        }
      }
      break;
    case 6 :
      analogWrite(led1,255);
      analogWrite(led2,255);
      analogWrite(led3,255); 
      analogWrite(led4,255); 
      analogWrite(led5,255); delay(9000);
      analogWrite(led3,0); delay(500);
      analogWrite(led2,0);
      analogWrite(led4,0);  delay(500);
      analogWrite(led1,0); 
      analogWrite(led5,0);
      break;
        
    case 5 :
      sn = 0;
      while(sn < waitTime){
        analogWrite(led5,255); delay(400);
        analogWrite(led4,225); delay(400);
        analogWrite(led3,100); delay(400);
        analogWrite(led2,20); 
        sn = sn + 1;
        Serial.println(" sn'nin değeri:" + String(sn));
        delay(100);
        bool trigger4 = digitalRead(dataPin4);
        bool trigger3 = digitalRead(dataPin3);
        bool trigger2 = digitalRead(dataPin2);
        bool trigger1 = digitalRead(dataPin1);
        
        if(trigger4){
          sn = 10;
          sn1 = 0;
          while(sn1 < waitTime){
            analogWrite(led5,175);
            analogWrite(led4,255);
            analogWrite(led3,205); 
            analogWrite(led2,100); 
            analogWrite(led1,20);
            sn1 = sn1 + 1; 
            Serial.println(" sn1'nin değeri:" + String(sn1));
            delay(1000);
            bool trigger3 = digitalRead(dataPin3);
            bool trigger5 = digitalRead(dataPin5);
            bool trigger2 = digitalRead(dataPin2);
            bool trigger1 = digitalRead(dataPin1);
            
            if(trigger3) {  
              sn1 = 10;
              sn2 = 0;
              while(sn2 < waitTime){
                analogWrite(led5,0);
                analogWrite(led4,175);
                analogWrite(led3,255); 
                analogWrite(led4,205); 
                analogWrite(led1,100);
                sn2 = sn2 + 1;
                Serial.println(" sn2'nin değeri:" + String(sn2));
                delay(1000);
                bool trigger5 = digitalRead(dataPin5);
                bool trigger4 = digitalRead(dataPin4);
                bool trigger2 = digitalRead(dataPin2);
                bool trigger1 = digitalRead(dataPin1);

                if(trigger2){
                  sn2 = 10;
                  sn3 = 0;
                  while(sn3 < waitTime) {
                    analogWrite(led4,0);
                    analogWrite(led3,205); 
                    analogWrite(led2,255); 
                    analogWrite(led1,205);
                    sn3 = sn3 + 1;
                    Serial.println(" sn3'nin değeri:" + String(sn3));
                    delay(1000);
                    bool trigger5 = digitalRead(dataPin5);
                    bool trigger4 = digitalRead(dataPin4);
                    bool trigger3 = digitalRead(dataPin3);
                    bool trigger1 = digitalRead(dataPin1);

                    if(trigger1){
                      sn3 = 10;
                      sn4 = 0;
                      while (sn4 < (waitTime-1)){
                          analogWrite(led3,0); 
                          analogWrite(led2,205); 
                          analogWrite(led1,255);
                          sn4 = sn4 + 1;
                          Serial.println(" sn4'nin değeri:" + String(sn4));
                          delay(1000);
                          bool trigger5 = digitalRead(dataPin5);
                          bool trigger4 = digitalRead(dataPin4);
                          bool trigger3 = digitalRead(dataPin3);
                          bool trigger2 = digitalRead(dataPin2);
                          if(trigger5 || trigger4 || trigger3 || trigger2 ){
                            Serial.println("Pathway bozuldu");
                            break;
                        }
                      }
                      analogWrite(led2,0); 
                      delay(300);
                      analogWrite(led1,0); 
                      Serial.println("sa");
                    }
                    if(trigger5 || trigger4 || trigger3 ){
                        Serial.println("Pathway bozuldu");
                        break;
                    }
                  }
                } if(trigger5 || trigger4 || trigger1 ){
                  Serial.println("Pathway bozuldu");
                  break;
                }
              }
            } if(trigger5 || trigger2|| trigger1){
              Serial.println("Pathway bozuldu");
              break; 
            }
           }
        } if(trigger3 || trigger2 || trigger1){
            Serial.println("Pathway bozuldu");
            break;
       }
    }
    digitalWrite(led1,LOW); digitalWrite(led2,LOW); digitalWrite(led3,LOW); digitalWrite(led4,LOW); digitalWrite(led5,LOW);
    break;
  delay(1000);
  }
}
}
