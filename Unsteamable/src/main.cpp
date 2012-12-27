#include <OgreException.h>


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __unix

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, 2);
    exit(1);
}

void handler()
{
    void *trace_elems[20];
    int trace_elem_count(backtrace( trace_elems, 20 ));
    char **stack_syms(backtrace_symbols( trace_elems, trace_elem_count ));
    for ( int i = 0 ; i < trace_elem_count ; ++i )
    {
        std::cout << stack_syms[i] << "\n";
    }
    free( stack_syms );

    exit(1);
}

#endif

#include "Unsteamable.h"
#ifdef __cplusplus
extern "C"
{
#endif


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain ( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main ( int argc, char *argv[] )
#endif
    {
#ifdef __unix
        std::set_terminate( handler );
        signal(SIGSEGV, handler);
#endif
        // Create application object
        Unsteamable usmb;
        try
        {
            usmb.run();
        }
        catch ( Ogre::Exception& e )
        {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox ( NULL, e.getFullDescription().c_str(),
                         "An exception has occured!",
                         MB_OK | MB_ICONERROR | MB_TASKMODAL );
#else
            std::cerr << "An exception has occured: "
                      << e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
