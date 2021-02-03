#ifndef FlameSensorKakarobot_h
#define FlameSensorKakarobot_h

#include <inttypes.h>

#define maxSensor 14

class FlameSensorKakarobot{
	public:
		FlameSensorKakarobot(uint8_t selA, uint8_t selB, uint8_t selC, uint8_t adcF, uint8_t adcB);
		void init(uint8_t selA, uint8_t selB, uint8_t selC, uint8_t adcF, uint8_t adcB);
		void getRawValue();
		uint32_t getValue(uint32_t position);
		uint32_t getValueF(uint32_t position);
		uint32_t getValueB(uint32_t position);
		uint32_t getRefF();
		uint32_t getRefB();
		uint32_t getPositionF();
		uint32_t getPositionB();
		uint32_t getPosition();
		
		uint32_t getValuePositionF();
		uint32_t getValuePositionB();
		uint32_t getValuePosition();
		
		uint8_t selectorA = 2;
		uint8_t selectorB = 3;
		uint8_t selectorC = 4;
		uint8_t pinADCF = 0;
		uint8_t pinADCB = 1; 
		uint32_t adcApi = 0;
		uint32_t adcValueF[8];
		uint32_t adcValueB[8];
		 

	private:
		void inMux(uint8_t out_ke); 
		const uint8_t sF[maxSensor/2] = {0,1,2,4,6,7,5};
		const uint8_t sB[maxSensor/2] = {0,1,2,4,6,7,5};
		const uint8_t sAll[maxSensor] = {0,1,2,4,6,7,5,0,1,2,4,6,7,5};
		const uint8_t refF = 3;
		const uint8_t refB = 3;
		uint32_t adcApi1[maxSensor];
		uint8_t titikApi = 0;
		uint8_t titikApiF = 0;
		uint8_t titikApiB = 0;

		
};
 
#endif