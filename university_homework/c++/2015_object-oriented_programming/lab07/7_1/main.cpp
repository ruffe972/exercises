#include <iostream>
using std::cout;


int main()
{
    class SomeException {};
    try
    {
        /// An object prints a message when the time for its death comes...
        class DestructorPrinter
        {
        public:
            /// Self-destruct and print a message
            ~DestructorPrinter()
            {
                cout << "Destructor was called.\n";
            }
            /// Warning is "unused variable"
            void preventCompilerWarning() const {}
        };
        DestructorPrinter object;
        object.preventCompilerWarning();
        throw SomeException();
    }
    catch (SomeException)
    {
        cout << "Exception was catched.\n";
    }
    return 0;
}
