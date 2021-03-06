# try to import json-lib: 1st try usjon, 2nd try simplejson, else import standard python json
try:
    import ujson as json
except ImportError:
    try:
        import simplejson as json
    except ImportError:
        import json

# Differing string types for Python 2 and 3
import sys
if sys.version_info >= (3, 0):
    string_types = (str,)
else:
    string_types = (str, unicode)

import bson
try:
    bson.BSON
except AttributeError:
    raise Exception(
        "BSON installation does not support all necessary features. "
        "Please use the MongoDB BSON implementation. "
        "See: https://github.com/RobotWebTools/rosbridge_suite/issues/198"
    )
