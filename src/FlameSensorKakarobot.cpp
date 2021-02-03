#include "FlameSensorKakarobot.h"

#include <Arduino.h>

#include <inttypes.h>

FlameSensorKakarobot::FlameSensorKakarobot(uint8_t selA, uint8_t selB, unsigned char selC, uint8_t adcF, uint8_t adcB){
	init(selA, selB, selC, adcF, adcB);
} 
 
void FlameSensorKakarobot::init(uint8_t selA, uint8_t selB, uint8_t selC, uint8_t adcF, uint8_t adcB){
	selectorA = selA;
	selectorB = selB;
	selectorC = selC;
	pinADCF = adcF;
	pinADCB = adcB;
	
	pinMode(selectorA,OUTPUT);
	pinMode(selectorB,OUTPUT);
	pinMode(selectorC,OUTPUT); 
} 


void FlameSensorKakarobot::inMux(uint8_t inputMux) {
  byte value1, value2, value3;

  value1 = 1 & (inputMux >> 0);
  value2 = 1 & (inputMux >> 1);
  value3 = 1 & (inputMux >> 2);

  digitalWrite(selectorA, value1);
  digitalWrite(selectorB, value2);
  digitalWrite(selectorC, value3);
}
 
void FlameSensorKakarobot::getRawValue(){
	uint32_t data;
	for(int x = 0; x<maxSensor; x++){
		inMux(x); 
		adcValueF[x] = analogRead(pinADCF); 
		adcValueF[x] = analogRead(pinADCB);
	}
	 
}

uint32_t FlameSensorKakarobot::getValue(uint32_t position){
	uint32_t data;

	inMux(sAll[position]);
	if(position<7){
		data = analogRead(pinADCF);
	}else{ 
		data = analogRead(pinADCB);
	} 
	return data; 
}

 
uint32_t FlameSensorKakarobot::getValueF(uint32_t position){ 
	inMux(sF[position]); 
	return analogRead(pinADCF);   
}

uint32_t FlameSensorKakarobot::getValueB(uint32_t position){ 
	inMux(sB[position]); 
	return analogRead(pinADCB);   
}

uint32_t FlameSensorKakarobot::getRefF(){ 
	inMux(refF); 
	return analogRead(pinADCF); 
}

uint32_t FlameSensorKakarobot::getRefB(){ 
	inMux(refB); 
	return analogRead(pinADCB); 
}

uint32_t FlameSensorKakarobot::getPosition(){
	
	for(int x = 0; x<maxSensor; x++){
		inMux(sAll[x]);
		if(x<maxSensor/2){
			adcApi1[x] = analogRead(pinADCF);
		}else{
			adcApi1[x] = analogRead(pinADCB);
		}
	   
		if(adcApi1[x] > adcApi){titikApi = x; adcApi = adcApi1[x];}
		else {titikApi = titikApi; adcApi = adcApi1[titikApi];}
	 
   } 
   return titikApi; 
}

uint32_t FlameSensorKakarobot::getPositionF(){
	
	for(int x = 0; x<maxSensor/2; x++){
		inMux(sF[x]); 
		adcApi1[x] = analogRead(pinADCF); 
	   
		if(adcApi1[x] > adcApi){titikApi = x; adcApi = adcApi1[x];}
		else {titikApi = titikApi; adcApi = adcApi1[titikApi];}
	 
   } 
   return titikApi; 
}


uint32_t FlameSensorKakarobot::getPositionB(){
	
	for(int x = 0; x<maxSensor/2; x++){
		inMux(sB[x]); 
		adcApi1[x] = analogRead(pinADCB); 
	   
		if(adcApi1[x] > adcApi){titikApi = x; adcApi = adcApi1[x];}
		else {titikApi = titikApi; adcApi = adcApi1[titikApi];}
	 
   } 
   return titikApi; 
}
 
uint32_t FlameSensorKakarobot::getValuePosition(){
	
	for(int x = 0; x<maxSensor; x++){
		inMux(sAll[x]);
		if(x<maxSensor/2){
			adcApi1[x] = analogRead(pinADCF);
		}else{
			adcApi1[x] = analogRead(pinADCB);
		}
	   
		if(adcApi1[x] > adcApi){titikApi = x; adcApi = adcApi1[x];}
		else {titikApi = titikApi; adcApi = adcApi1[titikApi];}
	 
   } 
   return adcApi; 
}

uint32_t FlameSensorKakarobot::getValuePositionF(){
	
	for(int x = 0; x<maxSensor/2; x++){
		inMux(sF[x]); 
		adcApi1[x] = analogRead(pinADCF); 
	   
		if(adcApi1[x] > adcApi){titikApi = x; adcApi = adcApi1[x];}
		else {titikApi = titikApi; adcApi = adcApi1[titikApi];}
	 
   } 
   return adcApi; 
}


uint32_t FlameSensorKakarobot::getValuePositionB(){
	
	for(int x = 0; x<maxSensor/2; x++){
		inMux(sB[x]); 
		adcApi1[x] = analogRead(pinADCB); 
	   
		if(adcApi1[x] > adcApi){titikApi = x; adcApi = adcApi1[x];}
		else {titikApi = titikApi; adcApi = adcApi1[titikApi];}
	 
   } 
   return adcApi; 
}
