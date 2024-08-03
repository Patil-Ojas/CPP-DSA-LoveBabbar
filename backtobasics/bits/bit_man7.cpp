#include <iostream>
using namespace std;

// Function to copy set bits in the range from y to x
int copySetBits(int x, int y, int l, int r) {
    // Calculate the mask for the range l to r
    int maskLength = r - l + 1;       // Length of the bit range
    int mask = ((1 << maskLength) - 1) << (l - 1);  // Create mask
    
    // Extract the bits from y that are set in the given range
    int setBits = y & mask;
    
    // Set these bits in x
    x = x | setBits;
    
    return x;
}

int main() {
    int x = 10;
    int y = 13;
    int l = 2;
    int r = 3;

    // Call the function to get the updated x
    int updatedX = copySetBits(x, y, l, r);

    // Output the updated x, so you can verify or do further operations
    cout << "Updated value of x: " << updatedX << endl;

    return 0;
}
