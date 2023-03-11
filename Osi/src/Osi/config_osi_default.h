
/***************************************************************************/
/*           HERE DEFINE THE PROJECT SPECIFIC PUBLIC MACROS                */
/*    These are only in effect in a setting that doesn't use configure     */
/***************************************************************************/

/* Version number of project */
#define OSI_VERSION      "trunk"

/* Major Version number of project */
#define OSI_VERSION_MAJOR   9999

/* Minor Version number of project */
#define OSI_VERSION_MINOR   9999

/* Release Version number of project */
#define OSI_VERSION_RELEASE 9999

#ifndef OSILIB_EXPORT
#if defined(_WIN32) && defined(DLL_EXPORT)
#define OSILIB_EXPORT __declspec(dllimport)
#else
#define OSILIB_EXPORT
#endif
#endif
