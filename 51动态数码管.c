#include <REGX51.H>
  
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};//表示十六进制数0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
		  while(xms--)
		  {
				 i = 2;
				j = 239;
				do
				{
					while (--j);
				} while (--i);
		  }
	
}


void Nixie(unsigned char Location,Number)//第一个参数表示它的位置，第二个显示数字
{
		 switch(Location)
		 {
		 	case 1:P2_4=1;P2_3=1;P2_2=1;break;//LED8，即显示8
			case 2:P2_4=1;P2_3=1;P2_2=0;break;//LED7
			case 3:P2_4=1;P2_3=0;P2_2=1;break;//LED6
			case 4:P2_4=1;P2_3=0;P2_2=0;break;//LED5
			case 5:P2_4=0;P2_3=1;P2_2=1;break;//LED4
			case 6:P2_4=0;P2_3=1;P2_2=0;break;//LED3
			case 7:P2_4=0;P2_3=0;P2_2=1;break;//LED2
			case 8:P2_4=0;P2_3=0;P2_2=0;break;//LED1	
		 }
		 //P0=0x7D; //0x7D表示6
		 P0=  NixieTable[Number];//用数组进行输入具体数值
		 Delay(1);
		 P0=0x00;
}

  void main()
  {
  	
  	while(1)
	{
	   Nixie(1,1); //输入1，显示数字1
	   //Delay(200);//延迟200毫秒	
	   Nixie(2,2); //输入2，显示数字2	 
	   //Delay(200);	
	   Nixie(3,3);//输入3，显示数字3
	   //Delay(200);	
	}
  }
