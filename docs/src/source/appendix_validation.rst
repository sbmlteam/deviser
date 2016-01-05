.. _validation:

Appendix C: Validation
======================

The table lists the errors and warnings that may be produced by validating
a package being defined within Deviser Edit.

+--------------+---------------------+--------------------------------------------+
| **Severity** | **Reference**       | **Message**                                |
+==============+=====================+============================================+
|  Error       | :ref:`pkg-name`     | Package: missing name attribute.           |
+--------------+---------------------+--------------------------------------------+
|  Error       | :ref:`pkg-fullname` | Package: missing full name attribute.      |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`pkg-number`   | Package: Number should end with 00.        |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`pkg-offset`   | Package: Offset should end with 00000.     |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`elementfield` | The attribute 'foo_name' of 'foo_classname'|
|              |                     | is of type SIdRef, but has no element set. | 
|              |                     | This is needed for validation purposes.    |
+--------------+---------------------+--------------------------------------------+
|  Error       | :ref:`elementfield` | The attribute 'foo_name' is of type        |
|              |                     | 'foo_type' but has no element defined, this| 
|              |                     | is a required attribute for that type.     |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`elementfield` | The attribute 'foo_name' of type 'foo_type'|
|              |                     | but has an element 'foo_element' defined,  | 
|              |                     | this attribute will not be used.           |
+--------------+---------------------+--------------------------------------------+
|  Error       | :ref:`typefield`    | The attribute 'foo_name' has no type       |
|              |                     | defined, this is                           | 
|              |                     | a required attribute.                      |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`typefield`    | The attribute 'foo_name' is of type        |
|              |                     | 'foo_type', this type is not known by      |
|              |                     | DEVISER and will have to be changed        |
|              |                     | manually in the generated code.            |
+--------------+---------------------+--------------------------------------------+
|  Error       | :ref:`enum_name`    | EnumValue 'count' of enum 'foo_enum_name'  |
|              |                     | has no value, this is a required attribute | 
+--------------+---------------------+--------------------------------------------+
|  Error       | :ref:`enum_name`    | EnumValue 'count' of enum 'foo_enum_name'  |
|              |                     | has no name, this is a required attribute  | 
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`listofbox`    | Class 'foo_classname' uses a list of       |
|              |                     | 'foo_other', which is not marked having    |
|              |                     | a list.                                    |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`listofbox`    | Plugin for 'foo_extension_point' uses a    |
|              |                     | list of 'foo_other', which is not marked   |
|              |                     | having a list.                             |
+--------------+---------------------+--------------------------------------------+
|  Error       | :ref:`inst-element` | The instantiation 'foo_xml_name'           |
|              |                     | has no element defined, this               | 
|              |                     | is a required attribute.                   |
+--------------+---------------------+--------------------------------------------+
|  Warning     | :ref:`isbase`       | Class 'foo_classname' is marked            |
|              |                     | 'isBaseClass', but not used.               |
+--------------+---------------------+--------------------------------------------+
|  Error       |  :ref:`typecode`    | The element 'foo_classname' has no         |
|              |                     | typecode defined, and it can not be        |
|              |                     | generated automatically.                   |
+--------------+---------------------+--------------------------------------------+

Note: The error messages will be populated with the names of attributes/classes/types etc.
as illustrated by the 'foo_xxx' placeholders above.

.. todo::
    Missing rules: XML Name for instantiations