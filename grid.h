//
// Project: Labyrinth Escape II
// Name: Ronak Chaudhuri
// Project Overview: Grid class created to produce a linked list Grid object,
// containing a cell structure, and a linked list. Grid class updated to
// initialize and use operators on a Grid object. Then creates a function in
// EscapeLabyrinth.h that allows you to travserse a grid depending on user
// string input. Using this, runs gdb to navigate through a maze and figure
// out the solution path to maze for both a regular and twisty maze.
//

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
    struct CELL {
        CELL* Next;
        T Val;
        size_t NumCols;  // total # of columns (0..NumCols-1)
        CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
            Next = _Next;
            Val = _Val;
            NumCols = _NumCols;
        }
    };

    size_t NumRows;  // total # of rows (0..NumRows-1)
    CELL** Rows;     // C array of linked lists
public:
    //
    // default constructor:
    //
    // Called automatically by C++ to construct a 4x4 Grid.  All
    // elements are initialized to the default value of T.
    //
    Grid() {
        // initialize 4 rows
        Rows = new CELL*[4];
        NumRows = 4;

        // allocate the first cell of the linked list with default value:
        for (size_t r = 0; r < NumRows; ++r) {
            Rows[r] = new CELL(nullptr, T(), 4);
            CELL* cur = Rows[r];

            // create the linked list for this row.
            for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
                cur->Next = new CELL(nullptr, T());
                cur = cur->Next;
            }
        }

    }

    //
    // parameterized constructor:
    //
    // Called automatically by C++ to construct a Grid with R rows,
    // where each row has C columns. All elements are initialized to
    // the default value of T.
    //
    Grid(size_t R, size_t C) {
        // initialize R rows
        Rows = new CELL*[R];
        NumRows = R;

        // allocate the first cell of the linked list with parameter value:
        for (size_t row = 0; row < NumRows; ++row) {
            Rows[row] = new CELL(nullptr, T(), C);
            CELL* curr = Rows[row];

            // create the linked list for this row.
            for(size_t col = 1; col < Rows[row]->NumCols; ++col) {
                curr->Next = new CELL(nullptr, T());
                curr = curr->Next;
            }
        }

    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the vector.
    // Iterates though every cell in each row and deletes them using previous and
    // current pointers
    //
    virtual ~Grid() {
        for (size_t r = 0; r < NumRows; ++r) {
            CELL* curr = Rows[r];
            CELL* prev = nullptr;
            while(curr != nullptr) {
                prev = curr;
                curr = curr->Next;
                delete prev;
            }
            Rows[r] = nullptr;
        }
        delete[] Rows;
        Rows = nullptr;
    }


    //
    // copy constructor:
    //
    // Called automatically by C++ to construct a Grid that contains a
    // copy of an existing Grid.  Example: this occurs when passing
    // Grid as a parameter by value
    //
    //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
    //   { ... }
    // Copies values of NumRows and Rows array, then for each Row index,
    // creates a cell and copies values for each column.
    //
    Grid(const Grid<T>& other) {
        this->NumRows = other.NumRows;
        this->Rows = new CELL*[this->NumRows];
        for (size_t r = 0; r < NumRows; ++r) {
            this->Rows[r] = new CELL(nullptr);
            this->Rows[r]->NumCols = other.Rows[r]->NumCols;
            this->Rows[r]->Val = other.Rows[r]->Val;
            CELL* curr = this->Rows[r];
            CELL* otherCurr = other.Rows[r];
            while(otherCurr->Next != nullptr) {
                curr->Next = new CELL(nullptr);
                curr = curr->Next;
                otherCurr = otherCurr->Next;
                curr->Val = otherCurr->Val;
            }
        }
    }

    //
    // copy operator=
    //
    // Called when you assign one vector into another, i.e. this = other;
    // First frees memory of grid, then...
    // Copies values of NumRows and Rows array, then for each Row index,
    // creates a cell and copies values for each column.
    //
    Grid& operator=(const Grid& other) {
        for (size_t r = 0; r < NumRows; ++r) {
            CELL* curr = this->Rows[r];
            CELL* prev = nullptr;
            while(curr != nullptr) {
                prev = curr;
                curr = curr->Next;
                delete prev;
            }
            Rows[r] = nullptr;
        }
        delete[] Rows;
        Rows = nullptr;
        this->NumRows = other.NumRows;
        this->Rows = new CELL*[this->NumRows];
        for (size_t r = 0; r < NumRows; ++r) {
            this->Rows[r] = new CELL(nullptr);
            this->Rows[r]->NumCols = other.Rows[r]->NumCols;
            this->Rows[r]->Val = other.Rows[r]->Val;
            CELL* curr = this->Rows[r];
            CELL* otherCurr = other.Rows[r];
            while(otherCurr->Next != nullptr) {
                curr->Next = new CELL(nullptr);
                curr = curr->Next;
                otherCurr = otherCurr->Next;
                curr->Val = otherCurr->Val;
            }
        }
        return *this;
    }

    //
    // numrows
    //
    // Returns the # of rows in the Grid.  The indices for these rows
    // are 0..numrows-1.
    //
    size_t numrows() const {
        return NumRows;
    }


    //
    // numcols
    //
    // Returns the # of columns in row r.  The indices for these columns
    // are 0..numcols-1.  For now, each row will have the same number of columns.
    //
    size_t numcols(size_t r) const {
        if (r < 0 || r >= NumRows) {
            throw out_of_range("Grid: out of bounds");
        }
        return Rows[r]->NumCols;
    }


    //
    // size
    //
    // Returns the total # of elements in the grid.
    //
    size_t size() const {
        return NumRows * Rows[0]->NumCols;
    }


    //
    // ()
    //
    // Returns a reference to the element at location (r, c); this
    // allows you to access the element or change it:
    //
    //    grid(r, c) = ...
    //    cout << grid(r, c) << endl;
    //
    // At the row index of Rows array, iterates through column index times
    // until it reach element location and returns it
    //
    T& operator()(size_t r, size_t c) {
        if (r < 0 || r >= NumRows || c < 0 || c >= Rows[0]->NumCols) {
            throw out_of_range("Grid: out of bounds");
        }
        CELL* curr = Rows[r];
        for(size_t col = 0; col < c; ++col) {
            curr = curr->Next;
        }
        return curr->Val;
    }

    //
    // _output
    //
    // Outputs the contents of the grid; for debugging purposes.  This is not
    // tested.
    //
    void _output() {
        for (size_t r = 0; r < NumRows; ++r) {
            CELL* curr = Rows[r];

            // For each row, prints each proceeding col value
            while(curr != nullptr) {
                cout << curr->Val << " ";
                curr = curr->Next;
            }
            cout << endl;
        }
    }

};
