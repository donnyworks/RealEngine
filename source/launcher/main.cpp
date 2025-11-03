

// Codebase of launcher. One file.

#include <stdio.h>

#ifdef LINUX
#include <dlfcn.h>
#endif

#ifdef WINDOWS
#include <windows.h>
#endif

typedef int (*enginemain)(int, char**);

int main(int argv, char **argc) {
	#ifdef WINDOWS
	//printf("Sorry, there is currently no Real Engine Launcher implementation for Windows.\r\n");
	HMODULE hModule = LoadLibrary("realengine.dll");

	if (hModule == NULL) {
	    // Handle error, e.g., the DLL was not found or could not be loaded
	    DWORD error = GetLastError(); // Get extended error information
		printf("Failed to load RealEngine library!");
	} else {
		enginemain myFunction = (enginemain)GetProcAddress(hModule, "main");

		if (myFunction == NULL) {
		    // Handle error, e.g., the function was not found in the DLL
		    DWORD error = GetLastError();
			printf("Failed to get 'main' function!");
		    // ...
		} else {
		    // Now you can call the function through the pointer
		    int result = myFunction(argv,argc);
		    FreeLibrary(hModule);
			hModule = NULL;
			return result
		}
	}
	return -1;
	#endif
	#ifdef LINUX
	void* handle = dlopen("./realengine.so", RTLD_LAZY);
	if (!handle) {
        // Handle error: library not found or cannot be loaded
        fprintf(stderr, "Cannot open library: %s\n", dlerror());
        return -1;
    }

    // Get the function pointer
    enginemain entrypoint = (enginemain)dlsym(handle, "main");
    if (!entrypoint) {
        // Handle error: function not found
        fprintf(stderr, "Cannot load symbol: %s\n", dlerror());
        // Clean up and exit
    }

    // Now you can call the function
    int result = entrypoint(argv,argc);
    dlclose(handle);
    return result;
	#endif
}
