<?xml version="1.0" encoding="UTF-8"?>
<app:application xmlns:app="http://www.sierrawireless.com/airvantage/application/1.0" name="COW" type="" revision="1.0.0">
  <application-manager use="LWM2M_SW"/>
  <capabilities>
    <communication use="legato"/>
    <data>
      <encoding type="LWM2M">
        <asset default-label="Application Objects" id="le_COW">
          <node default-label="Application Object" path="0">
            <variable default-label="Version" path="0" type="string"/>
            <variable default-label="Name" path="1" type="string"/>
            <variable default-label="State" path="2" type="int"/>
            <variable default-label="StartMode" path="3" type="int"/>
          </node>
          <node default-label="Process Object" path="1">
            <variable default-label="Name" path="0" type="string"/>
            <variable default-label="ExecName" path="1" type="string"/>
            <variable default-label="State" path="2" type="int"/>
            <variable default-label="FaultAction" path="3" type="int"/>
            <variable default-label="FaultCount" path="4" type="int"/>
            <variable default-label="FaultLogs" path="5" type="string"/>
          </node>
        </asset>
      </encoding>
    </data>
  </capabilities>
</app:application>
