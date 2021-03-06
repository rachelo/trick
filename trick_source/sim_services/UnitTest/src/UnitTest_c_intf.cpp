
#include <iostream>
#include <fstream>

#include "sim_services/UnitTest/include/UnitTest.hh"

extern Trick::UnitTest * the_unit_test_output ;

extern "C" int add_test_result( const char * in_test_suite_name , const char * in_test_case , const char * in_failure_string ) {
    if ( in_failure_string == NULL ) {
        in_failure_string = "" ;
    }
    the_unit_test_output->add_test_results(in_test_suite_name , in_test_case , in_failure_string ) ;
    return(0) ;
}

extern "C" int trick_test_add_parent(const char * in_test_suite_name, const char * in_test_case, const char * par_num ) {
	the_unit_test_output->add_test_requirements(in_test_suite_name, in_test_case, par_num);

	return(0);
}


extern "C" int call_write_output() {
    the_unit_test_output->write_output() ;
    return(0) ;
}

