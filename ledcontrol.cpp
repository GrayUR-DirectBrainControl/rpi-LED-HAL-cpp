#include <iostream>
#include "pigpio.h" //Not needed for now
#include <stdlib.h>

// Include the necessary BrainFlow headers
#include "brainflow/src/board_controller/inc/board_controller.h"  
#include "brainflow/cpp_package/src/inc/board_shim.h" 
#include "brainflow/src/utils/inc/brainflow_exception.h"


int main() {
    int board_id = (int)BoardIds::SYNTHETIC_BOARD;	//Testing brainflow library with synthetic board
    BrainFlowInputParams params;  
    BoardShim::set_log_file("brainflow.log");
    BoardShim::enable_dev_board_logger(); 

    try {
        BoardShim board(board_id, params);
        board.prepare_session();
		//if(is_prepared()){ replaced with try-catch method
			std::cout << "BrainFlow session started!" << std::endl;
		//}
        board.release_session();
    } catch (const BrainFlowException& e) {
        std::cerr << "BrainFlow error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}


/* RUN THIS TO COMPILE CODE(via terminal):

g++ -std=c++11 -o brainflow_test ledcontrol.cpp \
    -I/home/coolkidz/repos/rpi-LED-HAL-cpp/brainflow/src/board_controller/inc \
    -I/home/coolkidz/repos/rpi-LED-HAL-cpp/brainflow/cpp_package/src/inc \
    -I/home/coolkidz/repos/rpi-LED-HAL-cpp/brainflow/src/utils/inc \
    -I/home/coolkidz/repos/rpi-LED-HAL-cpp/brainflow/third_party/json \
    -L/home/coolkidz/repos/rpi-LED-HAL-cpp/brainflow/compiled \
    /home/coolkidz/repos/rpi-LED-HAL-cpp/brainflow/compiled/libBrainflow.a \
    -lBoardController -lpigpio -lpthread -lrt

*/