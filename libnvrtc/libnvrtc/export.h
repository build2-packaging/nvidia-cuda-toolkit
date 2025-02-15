#pragma once

#if defined(LIBNVRTC_STATIC)         /* Using static. */
#  define LIBNVRTC_SYMEXPORT
#elif defined(LIBNVRTC_STATIC_BUILD) /* Building static. */
#  define LIBNVRTC_SYMEXPORT
#elif defined(LIBNVRTC_SHARED)       /* Using shared. */
#  ifdef _WIN32
#    define LIBNVRTC_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBNVRTC_SYMEXPORT
#  endif
#elif defined(LIBNVRTC_SHARED_BUILD) /* Building shared. */
#  ifdef _WIN32
#    define LIBNVRTC_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBNVRTC_SYMEXPORT
#  endif
#else
/* If none of the above macros are defined, then we assume we are being used
 * by some third-party build system that cannot/doesn't signal the library
 * type. Note that this fallback works for both static and shared libraries
 * provided the library only exports functions (in other words, no global
 * exported data) and for the shared case the result will be sub-optimal
 * compared to having dllimport. If, however, your library does export data,
 * then you will probably want to replace the fallback with the (commented
 * out) error since it won't work for the shared case.
 */
#  define LIBNVRTC_SYMEXPORT         /* Using static or shared. */
/*#  error define LIBNVRTC_STATIC or LIBNVRTC_SHARED preprocessor macro to signal libnvrtc library type being linked */
#endif
