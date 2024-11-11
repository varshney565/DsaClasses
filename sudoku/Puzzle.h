class Puzzle {
private:
    // Inner class representing each square on the Sudoku grid
    class Square {
        private:
            int val; // Value in the square; -1 means uninitialized

        public:
            // Default constructor, initializes val to -1
            Square() {
                this->val = -1;
            }

            // Constructor to set a specific value
            Square(int value) {
                this->val = value;
            }

            // Getter for val
            int getValue() {
                return this->val;
            }

            // Setter for val
            void setValue(int value) {
                this->val = value;
            }
    };

    // 9x9 grid of Square objects
    vector<vector<Square>> grid;
    int variableEntries;  // Counts how many squares are initially filled
    int emptySquares;     // Counts how many squares are initially empty

    // Checks if placing the current value at (x, y) is valid
    bool check(int x, int y) {
        // Check the row and column
        for(int i = 0; i < 9; i++) {
            // Check row, ignoring the current cell itself
            if((i != x) && grid[i][y].getValue() == grid[x][y].getValue()) {
                return false;
            }
            // Check column, ignoring the current cell itself
            if((i != y) && grid[x][i].getValue() == grid[x][y].getValue()) {
                return false;
            }
        }

        // Check 3x3 subgrid containing (x, y)
        int startX = (x / 3) * 3;
        int startY = (y / 3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                // Check subgrid, ignoring the current cell itself
                if((i + startX != x && j + startY != y) &&
                   grid[i + startX][j + startY].getValue() == grid[x][y].getValue()) {
                    return false;
                }
            }
        }
        return true; // Value placement is valid
    }

    // Recursive backtracking function to solve the Sudoku
    bool helper(int x, int y) {
        // If we have completed all rows, the puzzle is solved
        if(x == 9) {
            return true;
        }
        // Move to the next cell
        int nextRow = ((y == 8) ? x + 1 : x); // If at the end of the row, move to the next row
        int nextCol = (y + 1) % 9; // Wrap around to the start of the next row if needed

        // If the cell is already filled, move to the next one
        if(grid[x][y].getValue() != 0) {
            return helper(nextRow, nextCol);
        }

        // Try values 1 through 9 in the empty cell
        for(int i = 1; i <= 9; i++) {
            grid[x][y].setValue(i); // Place a value
            if(check(x, y) && helper(nextRow, nextCol)) {
                return true; // Valid placement and the rest of the puzzle is solvable
            }
            grid[x][y].setValue(0); // Reset if not valid
        }
        return false; // No valid value found for this cell
    }

public:
    // Constructor initializes a 9x9 grid of Squares and resets counters
    Puzzle() {
        grid.resize(9, vector<Square>(9));
        variableEntries = 0;
        emptySquares = 0;
    }

    // Get the value of a specific cell
    int getValue(int x, int y) {
        return grid[x][y].getValue();
    }

    // Set a specific value for a cell
    void setValue(int x, int y, int val) {
        grid[x][y].setValue(val);
    }

    // Input stream operator to read in the puzzle and track filled/empty squares
    friend istream& operator>>(istream& in, Puzzle &p) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int val;
                in >> val;
                if(val == 0) {
                    p.emptySquares++; // Count empty cells
                } else {
                    p.variableEntries++; // Count pre-filled cells
                }
                p.setValue(i, j, val); // Set cell value
            }
        }
        return in;
    }

    // Output stream operator to print the puzzle in a structured format
    friend ostream& operator<<(ostream& out, Puzzle &p) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                out << p.getValue(i, j) << " "; // Print each cell
                if(j % 3 == 2 && j != 8) { // Vertical separators between 3x3 blocks
                    cout << "|";
                }
            }
            out << "\n";
            if(i % 3 == 2 && i != 8) { // Horizontal separators between 3x3 blocks
                cout << "------+-----+------";
            }
            cout << "\n";
        }
        return out;
    }

    // Returns the count of initially filled cells
    int size() const {
        return this->variableEntries;
    }

    // Returns the count of empty cells
    int numEmpty() const {
        return this->emptySquares;
    }

    // Public method to solve the puzzle
    bool solve() {
        return helper(0, 0);
    }
};
