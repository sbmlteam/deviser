
Appendix A: Example package description
========================================

The following is the XML description produced by the Deviser Edit tool and used by 
further generation facilities within Deviser.  The example given corresponds
to the examples used within the documentation to specify the "Imaginary Package
Foo".

.. code-block:: XML

    <?xml version="1.0" encoding="UTF-8"?>
    <package name="Foo" fullname="Imaginary Package Foo" number="2000" 
             offset="1400000" version="1" required="true">
      <versions>
        <pkgVersion level="3" version="1" pkg_version="1">
          <elements>
            <element name="FooParameter" typeCode="SBML_FOO_PARAMETER" 
                     hasListOf="true" minNumListOfChildren="1" baseClass="SBase" 
                     abstract="false" elementName="parameter" listOfName="listOfParameters" 
                     listOfClassName="ListOfFooParameters">
              <attributes>
                <attribute name="value" required="false" type="double" abstract="false"/>
                <attribute name="id" required="true" type="SId" abstract="false"/>
                <attribute name="units" required="false" type="UnitSIdRef" abstract="false"/>
                <attribute name="constant" required="true" type="boolean" abstract="false"/>
              </attributes>
              <listOfAttributes>
                <listOfAttribute name="local" required="true" type="bool" abstract="false"/>
              </listOfAttributes>
            </element>
            <element name="FooKineticLaw" typeCode="SBML_FOO_FOOKINETIC_LAW" 
                     hasListOf="false" baseClass="SBase" abstract="false" 
                     elementName="kineticLaw">
              <attributes>
                <attribute name="stochastic" required="true" type="boolean" abstract="false"/>
                <attribute name="listOfFooParameters" required="false" type="lo_element" 
                           element="FooParameter" xmlName="listOfParameters" abstract="false"/>
                <attribute name="math" required="true" type="element" element="ASTNode*" 
                           abstract="false"/>
              </attributes>
            </element>
            <element name="Assignment" typeCode="SBML_FOO_ASSIGNMENT" 
                     hasListOf="false" baseClass="FooRule" abstract="true">
              <attributes>
                <attribute name="variable" required="true" type="SIdRef" 
                           element="FooParameter" abstract="false"/>
              </attributes>
              <concretes>
                <concrete name="rate" element="FooRate"/>
                <concrete name="assignment" element="FooAssignment"/>
              </concretes>
            </element>
            <element name="FooRule" typeCode="SBML_FOO_RULE" hasListOf="true" 
                     minNumListOfChildren="1" baseClass="SBase" abstract="true">
              <attributes>
                <attribute name="math" required="true" type="element" element="ASTNode*" 
                           abstract="false"/>
              </attributes>
              <concretes>
                <concrete name="assignment" element="Assignment"/>
                <concrete name="algebraic" element="Algebraic"/>
              </concretes>
            </element>
            <element name="Extra" typeCode="SBML_FOO_EXTRA" hasListOf="false" 
                     baseClass="SBase" abstract="false">
              <attributes>
                <attribute name="sign" required="true" type="enum" element="Sign" 
                           abstract="false"/>
                <attribute name="qualitativeSpecies" required="false" type="element" 
                           element="QualitativeSpecies" abstract="false"/>
              </attributes>
            </element>
            <element name="Algebraic" typeCode="SBML_FOO_ALGEBRAIC" 
                     hasListOf="false" baseClass="FooRule" abstract="false"/>
            <element name="FooRate" typeCode="SBML_FOO_FOORATE" hasListOf="false" 
                     baseClass="Assignment" abstract="false" elementName="rate"/>
            <element name="FooAssignment" typeCode="SBML_FOO_FOOASSIGNMENT" 
                     hasListOf="false" baseClass="Assignment" abstract="false" 
                     elementName="assignment"/>
          </elements>
          <plugins>
            <plugin extensionPoint="Reaction">
              <references>
                <reference name="FooKineticLaw"/>
              </references>
            </plugin>
            <plugin extensionPoint="Model">
              <attributes>
                <attribute name="useFoo" required="true" type="boolean" abstract="false"/>
              </attributes>
            </plugin>
            <plugin typecode="SBML_QUAL_TRANSITION" package="qual" 
                    extensionPoint="Transition">
              <references>
                <reference name="ListOfFooRules"/>
              </references>
            </plugin>
            <plugin extensionPoint="Species">
              <references>
                <reference name="Extra"/>
              </references>
            </plugin>
          </plugins>
          <enums>
            <enum name="Sign">
              <enumValues>
                <enumValue name="SIGN_FOO_POSITIVE" value="positive"/>
                <enumValue name="SIGN_FOO_NEGATIVE" value="negative"/>
                <enumValue name="SIGN_FOO_NEUTRAL" value="neutral"/>
              </enumValues>
            </enum>
          </enums>
          <mappings>
            <mapping name="Transition" package="qual"/>
            <mapping name="QualitativeSpecies" package="qual"/>
          </mappings>
        </pkgVersion>
      </versions>
    </package>
