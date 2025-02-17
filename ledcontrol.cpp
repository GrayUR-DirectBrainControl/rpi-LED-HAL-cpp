#include <iostream>
#include "pigpio.h" 
#include <stdlib.h>

#include "brainflow/src/board_controller/inc/board_controller.h"

int main() {
    int board_id = (int)BoardIds::SYNTHETIC_BOARD;	//Testing brainflow library with synthetic board
    BrainFlowInputParams params; 
    BoardShim::set_log_file("brainflow.log");
    BoardShim::enable_dev_board_logger(); 

    try {
        BoardShim board(board_id, params);
        board.prepare_session();
		//if(is_prepared()){ replaces with try-catch method
			std::cout << "BrainFlow session started!" << std::endl;
		//}
        board.release_session();
    } catch (const BrainFlowException& e) {
        std::cerr << "BrainFlow error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}


