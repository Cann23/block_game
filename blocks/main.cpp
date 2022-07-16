#include <iostream>

// Global variables
int grid[9][9];
int temp_grid[9][9];
int shape[3][3];
int score = 0;


// read the shape from the input file
void read_shape(){
    for(int i = 0; i < 3; i++){

        // read the shape from the input
                for(int j = 0; j < 3; j++){
                    std::cin >> shape[i][j];
                }

//        // random shapes
//        for(int j = 0; j < 3; j++){
//            shape[i][j] = rand() % 2;
//        }
    }
    std:: cout << "The shape of the grid is: " << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << shape[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// TODO: check if there are any moves left


// check if the shape can be placed on the grid
bool check_shape(int x, int y){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(shape[i][j] != 0){
                if(grid[x+i][y+j] != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

// place shape on the grid
void place_shape(int x, int y){
    //check if the shape can be placed on the grid
    if(!check_shape(x, y)){
        std::cout << "Error: shape cannot be placed on the grid with these values" << std::endl;
        std::cout << "Penalty !!! -25 points from your score" << std::endl;
        score -= 25;
        return;
    }
    else{
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(shape[i][j] != 0){
                    grid[x+i][y+j] = shape[i][j];
                }
            }
        }
        std::cout << "You get 50 points for successful placement" << std::endl;
        score += 50;
        std::cout << "Shape placed on the grid" << std::endl;
    }
}

// check if the row is full
void check_row(int row, int temp_grid[9][9]){
    for(int i = 0; i < 9; i++){
        if(temp_grid[row][i] == 0){
            return;
        }
    }
    std::cout << row << ".row is full" << std::endl;
    std::cout << "This row is cleared" << std::endl;

    std::cout << "You get 100 points for clearing row successfully" << std::endl;
    score += 100;

    // clear the row
    for(int i = 0; i < 9; i++){
        grid[row][i] = 0;
    }
}

// check if the column is full
void check_column(int column, int temp_grid[9][9]){
    for(int i = 0; i < 9; i++){
        if(temp_grid[i][column] == 0){
            return;
        }
    }
    std::cout << column << ".column is full" << std::endl;
    std::cout << "This column is cleared" << std::endl;

    std::cout << "You get 100 points for clearing column successfully" << std::endl;
    score += 100;

    // clear the column
    for(int i = 0; i < 9; i++){
        grid[i][column] = 0;
    }
}

// check if the 3x3 box is full
void check_box(int x, int y, int temp_grid[9][9]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(temp_grid[x*3+i][y*3+j] == 0){
                return;
            }
        }
    }
    std::cout << "box is full and the center block of box: " << x+1 << " , " << y+1 << std::endl;
    std::cout << "This box is cleared" << std::endl;

    std::cout << "You get 100 points" << std::endl;
    score += 100;

    // clear the box
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            grid[x*3+i][y*3+j] = 0;
        }
    }
}

// check all the rows, columns and boxes
void check_all(){
    // set temp_grid to grid
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            temp_grid[i][j] = grid[i][j];
        }
    }

    for(int i = 0; i < 9; i++){
        check_row(i, temp_grid);
        check_column(i, temp_grid);
        check_box(i/3, i%3, temp_grid);
    }
}

// print the grid
void print_grid(){
    std:: cout << " The grid:" << std::endl;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    while(1){
        // read the shape
        read_shape();

        // print the grid
        print_grid();

        // x and y are the coordinates of the shape
        std::cout << "Enter x and y coordinates of the shape" << std::endl;
        int x, y;
        std::cin >> x >> y;

        // place the shape on the grid
        place_shape(x, y);

        // check all the rows, columns and boxes
        check_all();

        // print the grid
        print_grid();

        // print the score
        std::cout << "The score is: " << score << std::endl;

    }
    return 0;
}
