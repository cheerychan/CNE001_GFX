#include "printf.h"
#include "serial.h"
#include "cpu.h"
#include "vic.h"
#include "timer.h"
#include "io.h"
#include "string.h"
#include "pmu.h"
#include "dvfs_table.h"
#include "timestamp_autogenerated.h"


#define PMP_STRING  "PMP Version: " PMP_VERSION " - ""(Compiled By "COMPILE_BY "  " PMP_DATE" - "PMP_TIME")\n"

#if __GNUC__
#define __NO_RETURN __attribute__((noreturn))
#else
#define __NO_RETURN
#endif

unsigned int pmp_clock=200;


void main(void) __NO_RETURN;


void patches(void)
{

}

void main(void)
{	
#if PMU_DEBUG
	serial_init();
#endif	
	init_vic();
	pmu_init();	
		
	//init_pmp_timer(TIM_PERIOD);  //interrupt period ms

	//patches();
	//test_vector_init(); 
	//main_loop();
	while (1)
	{
		c3d_reg_mode_test();
		s3d0_reg_mode_test();
		//pcu_boost_reduce_test();

		//mdelay(1000);
	}
}
