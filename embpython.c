#include <Python.h>
#include <stdio.h>
/*
 * gcc embpython.c -I/usr/include/python2.7 -lpython 
 **/
void loadModule()
{
    /* run objects with low-level calls */
    char *arg1="sir", *arg2="robin", *cstr;
    printf("Load Module err!\n");
    PyObject *pmod, *pclass, *pargs, *pinst, *pmeth, *pres;
    /* instance = module.klass(  ) */
    pmod   = PyImport_ImportModule("module");
    if (pmod == NULL) {
        printf("Load Module err!\n");
        return;
    }
    /* fetch module */
    pclass = PyObject_GetAttrString(pmod, "klass");
    /* fetch module.class */
    Py_DECREF(pmod);
    pargs  = Py_BuildValue("(  )");
    pinst  = PyEval_CallObject(pclass, pargs);
    /* call class(  ) */
    Py_DECREF(pclass);
    Py_DECREF(pargs);
    /* result = instance.method(x,y) */
    pmeth  = PyObject_GetAttrString(pinst, "method");
    /* fetch bound method */
    Py_DECREF(pinst);
    pargs  = Py_BuildValue("(ss)", arg1, arg2);
    /* convert to Python */
    pres   = PyEval_CallObject(pmeth, pargs);
    /* call method(x,y) */
    Py_DECREF(pmeth);
    Py_DECREF(pargs);
    PyArg_Parse(pres, "s", &cstr);
    /* convert to C */
    printf("%s\n", cstr);
    Py_DECREF(pres);
}
/*
 * PyString_Check
 * PyList_Check
 * PyTuple_Check
 * PyDict_Check
 * PyInt_Check
 * PyBool_Check
 * PyClass_Check
 */

void enumDict(PyObject *dict)
{
    PyObject *list = PyDict_Keys(dict);
    Py_ssize_t n = PyList_Size(list);
    PyObject *obj = NULL;
    char *key = NULL;
    Py_ssize_t i = 0;
    for (i = 0; i < n; i++) {
        obj = PyList_GetItem(list, i);
        key = PyBytes_AsString(obj);
        PyObject *item = PyDict_GetItem(dict, obj);
        if (PySet_Check(item)) {
            printf("%s: %ld\n", key, PyLong_AsLong(item));
        }
        else if (PyMapping_Check(item)) {
            printf("%s: %s\n", key, PyBytes_AsString(item));
        }
        Py_DECREF(obj);
    }
    Py_DECREF(list);
}

void globalVars()
{
    PyRun_SimpleString("result = 5 ** 2");

    PyObject *module = PyImport_AddModule("__main__"); // borrowed reference
    assert(module);                                     // __main__ should always exist

    PyObject *dictionary = PyModule_GetDict(module);   // borrowed reference
    assert(dictionary);                                 // __main__ should have a dictionary

    PyObject *result = PyMapping_GetItemString(dictionary, "result");     // borrowed reference
    assert(result);                                     // just added result
    assert(PySet_Check(result));                        // result should be an integer
    long result_value = PyLong_AS_LONG(result);          // already checked that it is an int
    printf("%ld\n", result_value);
}

void parseBool()
{
    PyObject *module;
    PyObject *dict;
    PyObject *trueVal, *falseVal;

    PyRun_SimpleString("trueVal = True\nfalseVal = False");
    module = PyImport_AddModule("__main__");
    dict = PyModule_GetDict(module);
    trueVal = PyMapping_GetItemString(dict, "trueVal");
    falseVal = PyMapping_GetItemString(dict, "falseVal");

    assert(trueVal);
    if (Py_True == trueVal) {
        printf("True val.\n");
    }

    assert(falseVal);
    if (Py_False == falseVal) {
        printf("False val.\n");
    }
}

void useDict()
{
    PyObject * module;
    PyObject * dict;
    PyObject * dict2;
    PyObject * obj;
    long lval;

    PyRun_SimpleString("print (123)\nddd = {'a':2, 'b':'c'}\nprint (ddd)");
    module = PyImport_AddModule("__main__");
    dict = PyModule_GetDict(module);
    obj = PyMapping_GetItemString(dict, "ddd");

    if (obj != NULL)
    {
        enumDict(obj);
    }
    else
    {
        printf("Object not found\n");
    } /* if */
}

int_main()
{
    Py_Initialize();
    loadModule();
    parseBool();
    useDict();
    Py_Finalize();
    return 0;
}
