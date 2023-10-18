

/* section :includes */
#include"ECU_keypad.h"
/* section :macros declaration */

/* section :macros function  declaration */

/* section :data types */
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_ROWS] = {

    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}

    
};
/* section :function declaration  */

/**
 * @breif initialize the keypad pins
 * @param keypad pointer to keypad object
 * @return   E_OK : if function done SUCCESSFULY 
 *         E_NOT_OK : if function has issue 
 */
Std_ReturnType keypad_initialize(const keypad_t * keypad){
    
    uint8 row_counter,colomun_counter;
    
    Std_ReturnType ret=E_NOT_OK;
    if(NULL==keypad)
    {
        ret=E_NOT_OK;
    }
    else
    {
        for(row_counter=0;row_counter<ECU_KEYPAD_ROWS;row_counter++){
            
            ret=gpio_pin_initialize(&(keypad->keypad_row_pins[row_counter]));
        }
   for(colomun_counter=0;colomun_counter<ECU_KEYPAD_COLUMNS;colomun_counter++){
       ret=gpio_pin_initialize(&(keypad->keypad_columns_pins[colomun_counter]));
        }
    ret=E_OK;
    }
    return ret;
}

/**
 * @breif get the value  key pressed
 * @param keypad pointer to keypad object 
 * @param pointer to store the value of  pressed  key  
 * @return   E_OK : if function done SUCCESSFULY 
 *         E_NOT_OK : if function has issue 
 */
Std_ReturnType keypad_get_value(const keypad_t * keypad,uint8 * value){
    uint8 l_row_cunters,l_coloumns_counters;
    uint8 l_count,colum_logic;
     Std_ReturnType ret=E_NOT_OK;
    if(NULL==keypad|| NULL==value)
    {
        ret=E_NOT_OK;
    }
    else
    {
         for(l_row_cunters=0;l_row_cunters<ECU_KEYPAD_ROWS;l_row_cunters++){//super loop

            for (l_count = 0; l_count < ECU_KEYPAD_ROWS; l_count++) {
                gpio_pin_write_logic(&(keypad->keypad_row_pins[l_count]), LOW);
            }//make all rows with logic 0
         gpio_pin_write_logic(&(keypad->keypad_row_pins[l_row_cunters]),HIGH);
         
          for(l_coloumns_counters=0;l_coloumns_counters<ECU_KEYPAD_ROWS;l_coloumns_counters++){
              //reading the pressed button 
          gpio_pin_read_logic(&(keypad->keypad_columns_pins[l_coloumns_counters]),&colum_logic);
          if(colum_logic==HIGH){*value=btn_values[l_row_cunters][l_coloumns_counters];}
          }
         __delay_ms(1000);
         }
   
    ret=E_OK;
    }
    return ret;
}
/* keypad_t keypad_1= {.keypad_row_pins[0].direction = OUTPUT,
                        .keypad_row_pins[0].pin_index = pin0,
                        .keypad_row_pins[0].port_index = PORTC_INDEX,
                        .keypad_row_pins[0].pin_logic = LOW,
    //
                        .keypad_row_pins[1].direction = OUTPUT,
                        .keypad_row_pins[1].pin_index = pin1,
                        .keypad_row_pins[1].port_index = PORTC_INDEX,
                        .keypad_row_pins[1].pin_logic = LOW,
//
                        .keypad_row_pins[2].direction = OUTPUT,
                        .keypad_row_pins[2].pin_index = pin2,
                        .keypad_row_pins[2].port_index = PORTC_INDEX,
                        .keypad_row_pins[2].pin_logic = LOW,
    
                        .keypad_row_pins[3].direction = OUTPUT,
                        .keypad_row_pins[3].pin_index = pin3,
                        .keypad_row_pins[3].port_index = PORTC_INDEX,
                        .keypad_row_pins[3].pin_logic = LOW,
    //columns
                        .keypad_columns_pins[0].direction = INPUT,
                        .keypad_columns_pins[0].pin_index = pin4,
                        .keypad_columns_pins[0].port_index = PORTC_INDEX,
                        .keypad_columns_pins[0].pin_logic = LOW,
    //
                        .keypad_columns_pins[1].direction = INPUT,
                        .keypad_columns_pins[1].pin_index = pin5,
                        .keypad_columns_pins[1].port_index = PORTC_INDEX,
                        .keypad_columns_pins[1].pin_logic = LOW,
//
                        .keypad_columns_pins[2].direction = INPUT,
                        .keypad_columns_pins[2].pin_index = pin6,
                        .keypad_columns_pins[2].port_index = PORTC_INDEX,
                        .keypad_columns_pins[2].pin_logic = LOW,
    
                        .keypad_columns_pins[3].direction = INPUT,
                        .keypad_columns_pins[3].pin_index = pin7,
                        .keypad_columns_pins[3].port_index = PORTC_INDEX,
                        .keypad_columns_pins[3].pin_logic = LOW,
    
    
    
    };*/