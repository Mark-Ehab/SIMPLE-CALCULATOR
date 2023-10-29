/*
 * DIO_prg.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Mark
 */
#include "DIO_int.h"
#include "../../lib/stderrors.h"
#include "../../lib/DIO_Registers.h"
#include "../../lib/bitmath.h"

/*PORT level*/
u8 DIO_u8setPortDir(u8 Copy_u8port , u8 Copy_u8dir)
{
	u8 local_u8errStatus = RT_OK ;
	switch(Copy_u8port)
	{
	case PORT_A:
		DDRA_REG=Copy_u8dir;
		break;
	case PORT_B:
		DDRB_REG=Copy_u8dir;
		break;
	case PORT_C:
		DDRC_REG=Copy_u8dir;
		break;
	case PORT_D:
		DDRD_REG=Copy_u8dir;
		break;
	default:
		local_u8errStatus = RT_NOK ;
	}
	return local_u8errStatus ;
}

u8 DIO_u8setPortVal(u8 Copy_u8port , u8 Copy_u8dval)
{
	u8 local_u8errStatus = RT_OK ;
	switch(Copy_u8port)
	{
	case PORT_A:
		PORTA_REG=Copy_u8dval;
		break;
	case PORT_B:
		PORTB_REG=Copy_u8dval;
		break;
	case PORT_C:
		PORTC_REG=Copy_u8dval;
		break;
	case PORT_D:
		PORTD_REG=Copy_u8dval;
		break;
	default:
		local_u8errStatus = RT_NOK ;
	}
	return local_u8errStatus ;
}

u8 DIO_u8getPortVal(u8 Copy_u8port , u8* Copy_u8pval)
{
	u8 local_u8errStatus = RT_OK ;
	switch(Copy_u8port)
	{
	case PORT_A:
		*Copy_u8pval=PINA_REG;
		break;
	case PORT_B:
		*Copy_u8pval=PINB_REG;
		break;
	case PORT_C:
		*Copy_u8pval=PINC_REG;
		break;
	case PORT_D:
		*Copy_u8pval=PIND_REG;
		break;
	default:
		local_u8errStatus = RT_NOK ;
	}
	return local_u8errStatus ;
}
/*PIN level*/
u8 DIO_u8setPinDir(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8dir)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8pin >= PIN_0 && Copy_u8pin <= PIN_7 )
	{
		if(Copy_u8dir == INPUT)
		{
			switch(Copy_u8port)
			{
			case PORT_A:
				CLR_BIT(DDRA_REG,Copy_u8pin);
				break;
			case PORT_B:
				CLR_BIT(DDRB_REG,Copy_u8pin);
				break;
			case PORT_C:
				CLR_BIT(DDRC_REG,Copy_u8pin);
				break;
			case PORT_D:
				CLR_BIT(DDRD_REG,Copy_u8pin);
				break;
			default:
				local_u8errStatus = RT_NOK ;
			}
		}
		else if(Copy_u8dir == OUTPUT)
		{
			switch(Copy_u8port)
			{
			case PORT_A:
				SET_BIT(DDRA_REG,Copy_u8pin);
				break;
			case PORT_B:
				SET_BIT(DDRB_REG,Copy_u8pin);
				break;
			case PORT_C:
				SET_BIT(DDRC_REG,Copy_u8pin);
				break;
			case PORT_D:
				SET_BIT(DDRD_REG,Copy_u8pin);
				break;
			default:
				local_u8errStatus = RT_NOK ;
			}
		}
		else
		{
			local_u8errStatus = RT_NOK ;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return local_u8errStatus ;
}

u8 DIO_u8setPinVal(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8val)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8pin >= PIN_0 && Copy_u8pin <= PIN_7 )
	{
		if(Copy_u8val == LOW)
		{
			switch(Copy_u8port)
			{
			case PORT_A:
				CLR_BIT(PORTA_REG,Copy_u8pin);
				break;
			case PORT_B:
				CLR_BIT(PORTB_REG,Copy_u8pin);
				break;
			case PORT_C:
				CLR_BIT(PORTC_REG,Copy_u8pin);
				break;
			case PORT_D:
				CLR_BIT(PORTD_REG,Copy_u8pin);
				break;
			default:
				local_u8errStatus = RT_NOK ;
			}
		}
		else if(Copy_u8val == HIGH)
		{
			switch(Copy_u8port)
			{
			case PORT_A:
				SET_BIT(PORTA_REG,Copy_u8pin);
				break;
			case PORT_B:
				SET_BIT(PORTB_REG,Copy_u8pin);
				break;
			case PORT_C:
				SET_BIT(PORTC_REG,Copy_u8pin);
				break;
			case PORT_D:
				SET_BIT(PORTD_REG,Copy_u8pin);
				break;
			default:
				local_u8errStatus = RT_NOK ;
			}
		}
		else
		{
			local_u8errStatus = RT_NOK ;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return local_u8errStatus ;
}

u8 DIO_u8getPinVal(u8 Copy_u8port , u8 Copy_u8pin , u8* Copy_u8pval)
{
	u8 local_u8errStatus = RT_OK ;
	if(Copy_u8pin >= PIN_0 && Copy_u8pin <= PIN_7 )
	{
		switch(Copy_u8port)
		{
		case PORT_A:
			*Copy_u8pval=GET_BIT(PINA_REG,Copy_u8pin);
			break;
		case PORT_B:
			*Copy_u8pval=GET_BIT(PINB_REG,Copy_u8pin);
			break;
		case PORT_C:
			*Copy_u8pval=GET_BIT(PINC_REG,Copy_u8pin);
			break;
		case PORT_D:
			*Copy_u8pval=GET_BIT(PIND_REG,Copy_u8pin);
			break;
		default:
			local_u8errStatus = RT_NOK ;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK ;
	}
	return local_u8errStatus ;
}

