#ifndef GLIB_SHIM_H
#define GLIB_SHIM_H

#define GLIB_MAJOR_VERSION 3
#define GLIB_MINOR_VERSION 0
#define GLIB_MICRO_VERISON 0

#define GLIB_CHECK_VERSION(major,minor,micro)    \
    (GLIB_MAJOR_VERSION > (major) || \
     (GLIB_MAJOR_VERSION == (major) && GLIB_MINOR_VERSION > (minor)) || \
     (GLIB_MAJOR_VERSION == (major) && GLIB_MINOR_VERSION == (minor) && \
      GLIB_MICRO_VERSION >= (micro)))

typedef int GMutex;
typedef int GRecMutex;
typedef int GThread;
typedef int GCond;
typedef int GStatBuf;
typedef int GTimeVal;
typedef void* gpointer;
typedef int GError;

#ifdef WORDS_BIGENDIAN
#define G_BIG_ENDIAN WORDS_BIGENDIAN
#define G_BYTE_ORDER WORDS_BIGENDIAN
#else
#define G_BYTE_ORDER 0
#define G_BIG_ENDIAN 1
#endif

#define GINT32_FROM_LE(x) ((x))
#define GINT16_FROM_LE(x) ((x))

#define G_LIKELY
#define G_UNLIKELY

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define g_mutex_init(x)
#define g_mutex_clear(x)
#define g_mutex_lock(x)
#define g_mutex_unlock(x)

#define g_rec_mutex_init(x)
#define g_rec_mutex_clear(x)
#define g_rec_mutex_lock(x)
#define g_rec_mutex_unlock(x)

#define g_new(type, len) ( NULL )
#define g_free(obj)

#define g_atomic_int_inc(_pi) ( *_pi += 1 )
#define g_atomic_int_get(_pi) ( *_pi )
#define g_atomic_int_set(_pi, _val) ( *_pi = _val )
int g_atomic_int_dec_and_test(int* _pi);
#define g_atomic_int_compare_and_exchange(_pi, _old, _new) ( 1 )
int g_atomic_int_add(int* _pi, int _add);
#define g_atomic_pointer_get(_pp)           ( _pp )
#define g_atomic_pointer_set(_pp, val)      ( _pp = val )
#define g_atomic_pointer_compare_and_exchange(_pp, _expected, _desired) (1)

#define g_cond_init(x)
#define g_cond_signal(x)
#define g_cond_broadcast(x)
#define g_cond_clear(x)
#define g_cond_wait(x, y)

#define g_stat(a, b) ( 0 )

#define g_assert(a)

#define G_FILE_TEST_IS_REGULAR 0
#define G_FILE_TEST_EXISTS 1
#define g_file_test(a, b) ( FALSE )

#define g_usleep(x)

#define g_thread_try_new(a, b, c, d) ( NULL )
#define g_clear_error(e) ( *err = 0 )
#define g_thread_unref(t)
#define g_thread_join(t)

#define g_shim_alloca(size) _alloca((size))
#define g_newa(struct_type, n_structs) \
    ((struct_type *)g_shim_alloca(sizeof(struct_type) * (size_t)(n_structs)))

#endif
