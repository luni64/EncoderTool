<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="50" unitdist="mil" unit="mil" style="lines" multiple="2" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="yes" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="yes" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="yes" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="yes" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="yes" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="yes" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="yes" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="yes" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="yes" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="yes" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="yes" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="yes" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="yes" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="yes" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="yes" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="yes" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="yes" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="yes" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="yes" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="yes" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="yes" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="yes" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="DINA4_L" urn="urn:adsk.eagle:symbol:13867/1" library_version="1">
<frame x1="0" y1="0" x2="264.16" y2="180.34" columns="4" rows="4" layer="94" border-left="no" border-top="no" border-right="no" border-bottom="no"/>
</symbol>
<symbol name="DOCFIELD" urn="urn:adsk.eagle:symbol:13864/1" library_version="1">
<wire x1="0" y1="0" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="87.63" y2="15.24" width="0.1016" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="71.12" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="0" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="87.63" y1="5.08" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="22.86" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="15.24" width="0.1016" layer="94"/>
<text x="1.27" y="1.27" size="2.54" layer="94">Date:</text>
<text x="12.7" y="1.27" size="2.54" layer="94">&gt;LAST_DATE_TIME</text>
<text x="72.39" y="1.27" size="2.54" layer="94">Sheet:</text>
<text x="86.36" y="1.27" size="2.54" layer="94">&gt;SHEET</text>
<text x="88.9" y="11.43" size="2.54" layer="94">REV:</text>
<text x="1.27" y="19.05" size="2.54" layer="94">TITLE:</text>
<text x="1.27" y="11.43" size="2.54" layer="94">Document Number:</text>
<text x="17.78" y="19.05" size="2.54" layer="94">&gt;DRAWING_NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="DINA4_L" urn="urn:adsk.eagle:component:13919/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with extra doc field</description>
<gates>
<gate name="G$1" symbol="DINA4_L" x="0" y="0"/>
<gate name="G$2" symbol="DOCFIELD" x="162.56" y="0" addlevel="must"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="misc" urn="urn:adsk.eagle:library:17210741">
<packages>
<package name="ENCODER" urn="urn:adsk.eagle:footprint:17210742/1" library_version="1" library_locally_modified="yes">
<pad name="A" x="-2.5" y="-7.5" drill="1" shape="octagon"/>
<pad name="B" x="0" y="-7.5" drill="1" shape="octagon"/>
<pad name="C" x="2.5" y="-7.5" drill="1" shape="octagon"/>
<pad name="S2" x="2.5" y="7" drill="1" shape="octagon"/>
<pad name="S1" x="-2.5" y="7" drill="1" shape="octagon"/>
<pad name="G@1" x="-6.5" y="0" drill="2.6" shape="square"/>
<pad name="G@2" x="6.5" y="0" drill="2.6" shape="square"/>
<wire x1="-6" y1="7.5" x2="6" y2="7.5" width="0.127" layer="51"/>
<wire x1="6" y1="7.5" x2="6" y2="-6.5" width="0.127" layer="51"/>
<wire x1="6" y1="-6.5" x2="-6" y2="-6.5" width="0.127" layer="51"/>
<wire x1="-6" y1="-6.5" x2="-6" y2="7.5" width="0.127" layer="51"/>
<wire x1="-1.5" y1="2" x2="1.5" y2="2" width="0.127" layer="51"/>
<wire x1="1.5" y1="2" x2="-1.5" y2="2" width="0.127" layer="51" curve="-286.260205"/>
<wire x1="-6" y1="2.5" x2="-6" y2="7.5" width="0.127" layer="21"/>
<wire x1="-6" y1="7.5" x2="-4" y2="7.5" width="0.127" layer="21"/>
<wire x1="-1" y1="7.5" x2="0.5" y2="7.5" width="0.127" layer="21"/>
<wire x1="4" y1="7.5" x2="6" y2="7.5" width="0.127" layer="21"/>
<wire x1="6" y1="7.5" x2="6" y2="3" width="0.127" layer="21"/>
<wire x1="6" y1="-3" x2="6" y2="-6.5" width="0.127" layer="21"/>
<wire x1="6" y1="-6.5" x2="4" y2="-6.5" width="0.127" layer="21"/>
<wire x1="-4" y1="-6.5" x2="-6" y2="-6.5" width="0.127" layer="21"/>
<wire x1="-6" y1="-6.5" x2="-6" y2="-3" width="0.127" layer="21"/>
<wire x1="-1.5" y1="2" x2="1.5" y2="2" width="0.127" layer="21"/>
<wire x1="1.5" y1="2" x2="-1.5" y2="2" width="0.127" layer="21" curve="-286.260205"/>
<text x="-10" y="8.5" size="1.27" layer="25">&gt;NAME</text>
<text x="5" y="-8.5" size="1.27" layer="27">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="ENCODER" urn="urn:adsk.eagle:package:17210756/4" type="model" library_version="1" library_locally_modified="yes">
<packageinstances>
<packageinstance name="ENCODER"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="ENC_SW" urn="urn:adsk.eagle:symbol:17210745/1" library_version="1" library_locally_modified="yes">
<pin name="A" x="-2.54" y="-8.89" length="short" direction="pas" rot="R90"/>
<pin name="B" x="0" y="-8.89" length="short" direction="pas" rot="R90"/>
<pin name="C" x="2.54" y="-8.89" length="short" direction="pas" rot="R90"/>
<pin name="S1" x="-2.54" y="8.89" length="short" direction="pas" rot="R270"/>
<pin name="S2" x="2.54" y="8.89" length="short" direction="pas" rot="R270"/>
<pin name="G@2" x="6.35" y="0" length="point" direction="pas"/>
<pin name="G@1" x="-6.35" y="0" length="point" direction="pas" rot="R180"/>
<wire x1="-2.54" y1="-5.08" x2="-3.81" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="3.81" y2="-5.08" width="0.254" layer="94"/>
<wire x1="0" y1="-6.35" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="2.54" y2="3.81" width="0.254" layer="94"/>
<wire x1="-6.35" y1="6.35" x2="-2.54" y2="6.35" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="6.35" x2="2.54" y2="6.35" width="0.1524" layer="94"/>
<wire x1="2.54" y1="6.35" x2="6.35" y2="6.35" width="0.1524" layer="94"/>
<wire x1="6.35" y1="6.35" x2="6.35" y2="-6.35" width="0.1524" layer="94"/>
<wire x1="6.35" y1="-6.35" x2="2.54" y2="-6.35" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-6.35" x2="0" y2="-6.35" width="0.1524" layer="94"/>
<wire x1="0" y1="-6.35" x2="-2.54" y2="-6.35" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-6.35" x2="-6.35" y2="-6.35" width="0.1524" layer="94"/>
<wire x1="-6.35" y1="-6.35" x2="-6.35" y2="6.35" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="6.35" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="6.35" x2="2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-6.35" x2="-2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-6.35" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<circle x="-2.54" y="0" radius="0.635" width="0.254" layer="94"/>
<circle x="2.54" y="0" radius="0.635" width="0.254" layer="94"/>
<circle x="0" y="0" radius="0.3048" width="0.508" layer="94"/>
<circle x="-2.54" y="5.08" radius="0.635" width="0.254" layer="94"/>
<text x="-10.795" y="6.985" size="1.27" layer="95">&gt;NAME</text>
<text x="5.08" y="-8.255" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ENCODER" urn="urn:adsk.eagle:component:17210759/1" locally_modified="yes" prefix="EN" library_version="1" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="ENC_SW" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ENCODER">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="B" pad="B"/>
<connect gate="G$1" pin="C" pad="C"/>
<connect gate="G$1" pin="G@1" pad="G@1"/>
<connect gate="G$1" pin="G@2" pad="G@2"/>
<connect gate="G$1" pin="S1" pad="S1"/>
<connect gate="G$1" pin="S2" pad="S2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:17210756/4"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-panduit" urn="urn:adsk.eagle:library:169">
<description>&lt;b&gt;Panduit Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="057-026-0" urn="urn:adsk.eagle:footprint:9170/1" library_version="2">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
series 057 contact pc board low profile headers&lt;p&gt;
angled</description>
<wire x1="-1.9" y1="-0.23" x2="-1.9" y2="5.86" width="0.2032" layer="21"/>
<wire x1="-1.9" y1="-0.23" x2="1.9" y2="-0.23" width="0.2032" layer="21"/>
<wire x1="1.9" y1="-0.23" x2="1.9" y2="5.86" width="0.2032" layer="21"/>
<wire x1="-15.96" y1="5.22" x2="-15.26" y2="3.25" width="0.4064" layer="21"/>
<wire x1="-15.26" y1="3.25" x2="-14.56" y2="5.22" width="0.4064" layer="21"/>
<wire x1="-14.56" y1="5.22" x2="-15.96" y2="5.22" width="0.4064" layer="21"/>
<wire x1="-20.37" y1="-2.54" x2="-20.37" y2="5.86" width="0.2032" layer="21"/>
<wire x1="20.37" y1="5.86" x2="20.37" y2="-2.44" width="0.2032" layer="21"/>
<wire x1="-20.32" y1="-2.54" x2="-17.78" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="-17.78" y1="-2.54" x2="-17.78" y2="-5.98" width="0.2032" layer="21"/>
<wire x1="20.32" y1="-2.54" x2="17.78" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="17.78" y1="-2.54" x2="17.78" y2="-6.05" width="0.2032" layer="21"/>
<wire x1="17.77" y1="-6.04" x2="-17.77" y2="-6.04" width="0.2032" layer="21"/>
<wire x1="-20.37" y1="5.86" x2="20.37" y2="5.86" width="0.2032" layer="21"/>
<pad name="1" x="-15.24" y="-5.08" drill="1" shape="octagon"/>
<pad name="2" x="-15.24" y="-2.54" drill="1" shape="octagon"/>
<pad name="3" x="-12.7" y="-5.08" drill="1" shape="octagon"/>
<pad name="4" x="-12.7" y="-2.54" drill="1" shape="octagon"/>
<pad name="5" x="-10.16" y="-5.08" drill="1" shape="octagon"/>
<pad name="6" x="-10.16" y="-2.54" drill="1" shape="octagon"/>
<pad name="7" x="-7.62" y="-5.08" drill="1" shape="octagon"/>
<pad name="8" x="-7.62" y="-2.54" drill="1" shape="octagon"/>
<pad name="9" x="-5.08" y="-5.08" drill="1" shape="octagon"/>
<pad name="10" x="-5.08" y="-2.54" drill="1" shape="octagon"/>
<pad name="11" x="-2.54" y="-5.08" drill="1" shape="octagon"/>
<pad name="12" x="-2.54" y="-2.54" drill="1" shape="octagon"/>
<pad name="13" x="0" y="-5.08" drill="1" shape="octagon"/>
<pad name="14" x="0" y="-2.54" drill="1" shape="octagon"/>
<pad name="15" x="2.54" y="-5.08" drill="1" shape="octagon"/>
<pad name="16" x="2.54" y="-2.54" drill="1" shape="octagon"/>
<pad name="17" x="5.08" y="-5.08" drill="1" shape="octagon"/>
<pad name="18" x="5.08" y="-2.54" drill="1" shape="octagon"/>
<pad name="19" x="7.62" y="-5.08" drill="1" shape="octagon"/>
<pad name="20" x="7.62" y="-2.54" drill="1" shape="octagon"/>
<pad name="21" x="10.16" y="-5.08" drill="1" shape="octagon"/>
<pad name="22" x="10.16" y="-2.54" drill="1" shape="octagon"/>
<pad name="23" x="12.7" y="-5.08" drill="1" shape="octagon"/>
<pad name="24" x="12.7" y="-2.54" drill="1" shape="octagon"/>
<pad name="25" x="15.24" y="-5.08" drill="1" shape="octagon"/>
<pad name="26" x="15.24" y="-2.54" drill="1" shape="octagon"/>
<text x="-15.24" y="-8.89" size="1.778" layer="25">&gt;NAME</text>
<text x="3.81" y="2.54" size="1.778" layer="27">&gt;VALUE</text>
<hole x="-23.64" y="3.66" drill="2.8"/>
<hole x="23.89" y="3.66" drill="2.8"/>
</package>
<package name="057-026-1" urn="urn:adsk.eagle:footprint:9171/1" library_version="2">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
series 057 contact pc board low profile headers&lt;p&gt;
straight</description>
<wire x1="-1.9" y1="-3.32" x2="-1.9" y2="-4.03" width="0.2032" layer="21"/>
<wire x1="1.9" y1="-3.32" x2="1.9" y2="-4.03" width="0.2032" layer="21"/>
<wire x1="-17.66" y1="-1.97" x2="-16.96" y2="-3.04" width="0.4064" layer="21"/>
<wire x1="-16.96" y1="-3.04" x2="-16.26" y2="-1.97" width="0.4064" layer="21"/>
<wire x1="-16.26" y1="-1.97" x2="-17.66" y2="-1.97" width="0.4064" layer="21"/>
<wire x1="-20.37" y1="-4.1" x2="-20.37" y2="4.1" width="0.2032" layer="21"/>
<wire x1="-20.37" y1="-4.1" x2="20.37" y2="-4.1" width="0.2032" layer="21"/>
<wire x1="20.37" y1="-4.1" x2="20.37" y2="4.1" width="0.2032" layer="21"/>
<wire x1="20.37" y1="4.1" x2="-20.37" y2="4.1" width="0.2032" layer="21"/>
<wire x1="-19.57" y1="-3.3" x2="-19.57" y2="3.3" width="0.2032" layer="21"/>
<wire x1="-19.57" y1="3.3" x2="19.57" y2="3.3" width="0.2032" layer="21"/>
<wire x1="19.57" y1="3.3" x2="19.57" y2="-3.3" width="0.2032" layer="21"/>
<wire x1="19.57" y1="-3.3" x2="1.9" y2="-3.3" width="0.2032" layer="21"/>
<wire x1="-1.9" y1="-3.3" x2="-19.57" y2="-3.3" width="0.2032" layer="21"/>
<wire x1="-20.37" y1="4.1" x2="-19.57" y2="3.3" width="0.2032" layer="21"/>
<wire x1="-20.37" y1="-4.1" x2="-19.57" y2="-3.3" width="0.2032" layer="21"/>
<wire x1="20.37" y1="4.1" x2="19.57" y2="3.3" width="0.2032" layer="21"/>
<wire x1="19.57" y1="-3.3" x2="20.37" y2="-4.1" width="0.2032" layer="21"/>
<pad name="1" x="-15.24" y="-1.27" drill="1" shape="octagon"/>
<pad name="2" x="-15.24" y="1.27" drill="1" shape="octagon"/>
<pad name="3" x="-12.7" y="-1.27" drill="1" shape="octagon"/>
<pad name="4" x="-12.7" y="1.27" drill="1" shape="octagon"/>
<pad name="5" x="-10.16" y="-1.27" drill="1" shape="octagon"/>
<pad name="6" x="-10.16" y="1.27" drill="1" shape="octagon"/>
<pad name="7" x="-7.62" y="-1.27" drill="1" shape="octagon"/>
<pad name="8" x="-7.62" y="1.27" drill="1" shape="octagon"/>
<pad name="9" x="-5.08" y="-1.27" drill="1" shape="octagon"/>
<pad name="10" x="-5.08" y="1.27" drill="1" shape="octagon"/>
<pad name="11" x="-2.54" y="-1.27" drill="1" shape="octagon"/>
<pad name="12" x="-2.54" y="1.27" drill="1" shape="octagon"/>
<pad name="13" x="0" y="-1.27" drill="1" shape="octagon"/>
<pad name="14" x="0" y="1.27" drill="1" shape="octagon"/>
<pad name="15" x="2.54" y="-1.27" drill="1" shape="octagon"/>
<pad name="16" x="2.54" y="1.27" drill="1" shape="octagon"/>
<pad name="17" x="5.08" y="-1.27" drill="1" shape="octagon"/>
<pad name="18" x="5.08" y="1.27" drill="1" shape="octagon"/>
<pad name="19" x="7.62" y="-1.27" drill="1" shape="octagon"/>
<pad name="20" x="7.62" y="1.27" drill="1" shape="octagon"/>
<pad name="21" x="10.16" y="-1.27" drill="1" shape="octagon"/>
<pad name="22" x="10.16" y="1.27" drill="1" shape="octagon"/>
<pad name="23" x="12.7" y="-1.27" drill="1" shape="octagon"/>
<pad name="24" x="12.7" y="1.27" drill="1" shape="octagon"/>
<pad name="25" x="15.24" y="-1.27" drill="1" shape="octagon"/>
<pad name="26" x="15.24" y="1.27" drill="1" shape="octagon"/>
<text x="-15.22" y="-6.88" size="1.778" layer="25">&gt;NAME</text>
<text x="-15.97" y="4.55" size="1.778" layer="27">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="057-026-0" urn="urn:adsk.eagle:package:9189/1" type="box" library_version="2">
<description>CONNECTOR
series 057 contact pc board low profile headers
angled</description>
<packageinstances>
<packageinstance name="057-026-0"/>
</packageinstances>
</package3d>
<package3d name="057-026-1" urn="urn:adsk.eagle:package:9202/1" type="box" library_version="2">
<description>CONNECTOR
series 057 contact pc board low profile headers
straight</description>
<packageinstances>
<packageinstance name="057-026-1"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MV" urn="urn:adsk.eagle:symbol:9158/1" library_version="2">
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.1524" layer="94"/>
<text x="1.016" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-2.54" y="1.905" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M" urn="urn:adsk.eagle:symbol:9159/1" library_version="2">
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.1524" layer="94"/>
<text x="1.016" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="057-026-" urn="urn:adsk.eagle:component:9213/2" prefix="X" library_version="2">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
20-pin series 057 contact pc board low profile headers</description>
<gates>
<gate name="-1" symbol="MV" x="-10.16" y="43.18" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="12.7" y="43.18" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="-10.16" y="38.1" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="12.7" y="38.1" addlevel="always" swaplevel="1"/>
<gate name="-5" symbol="M" x="-10.16" y="33.02" addlevel="always" swaplevel="1"/>
<gate name="-6" symbol="M" x="12.7" y="33.02" addlevel="always" swaplevel="1"/>
<gate name="-7" symbol="M" x="-10.16" y="27.94" addlevel="always" swaplevel="1"/>
<gate name="-8" symbol="M" x="12.7" y="27.94" addlevel="always" swaplevel="1"/>
<gate name="-9" symbol="M" x="-10.16" y="22.86" addlevel="always" swaplevel="1"/>
<gate name="-10" symbol="M" x="12.7" y="22.86" addlevel="always" swaplevel="1"/>
<gate name="-11" symbol="M" x="-10.16" y="17.78" addlevel="always" swaplevel="1"/>
<gate name="-12" symbol="M" x="12.7" y="17.78" addlevel="always" swaplevel="1"/>
<gate name="-13" symbol="M" x="-10.16" y="12.7" addlevel="always" swaplevel="1"/>
<gate name="-14" symbol="M" x="12.7" y="12.7" addlevel="always" swaplevel="1"/>
<gate name="-15" symbol="M" x="-10.16" y="7.62" addlevel="always" swaplevel="1"/>
<gate name="-16" symbol="M" x="12.7" y="7.62" addlevel="always" swaplevel="1"/>
<gate name="-17" symbol="M" x="-10.16" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-18" symbol="M" x="12.7" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-19" symbol="M" x="-10.16" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-20" symbol="M" x="12.7" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-21" symbol="M" x="-10.16" y="-7.62" addlevel="always" swaplevel="1"/>
<gate name="-22" symbol="M" x="12.7" y="-7.62" addlevel="always" swaplevel="1"/>
<gate name="-23" symbol="M" x="-10.16" y="-12.7" addlevel="always" swaplevel="1"/>
<gate name="-24" symbol="M" x="12.7" y="-12.7" addlevel="always" swaplevel="1"/>
<gate name="-25" symbol="M" x="-10.16" y="-17.78" addlevel="always" swaplevel="1"/>
<gate name="-26" symbol="M" x="12.7" y="-17.78" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="0" package="057-026-0">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-14" pin="S" pad="14"/>
<connect gate="-15" pin="S" pad="15"/>
<connect gate="-16" pin="S" pad="16"/>
<connect gate="-17" pin="S" pad="17"/>
<connect gate="-18" pin="S" pad="18"/>
<connect gate="-19" pin="S" pad="19"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-20" pin="S" pad="20"/>
<connect gate="-21" pin="S" pad="21"/>
<connect gate="-22" pin="S" pad="22"/>
<connect gate="-23" pin="S" pad="23"/>
<connect gate="-24" pin="S" pad="24"/>
<connect gate="-25" pin="S" pad="25"/>
<connect gate="-26" pin="S" pad="26"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:9189/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
<device name="1" package="057-026-1">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-14" pin="S" pad="14"/>
<connect gate="-15" pin="S" pad="15"/>
<connect gate="-16" pin="S" pad="16"/>
<connect gate="-17" pin="S" pad="17"/>
<connect gate="-18" pin="S" pad="18"/>
<connect gate="-19" pin="S" pad="19"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-20" pin="S" pad="20"/>
<connect gate="-21" pin="S" pad="21"/>
<connect gate="-22" pin="S" pad="22"/>
<connect gate="-23" pin="S" pad="23"/>
<connect gate="-24" pin="S" pad="24"/>
<connect gate="-25" pin="S" pad="25"/>
<connect gate="-26" pin="S" pad="26"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:9202/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC" urn="urn:adsk.eagle:symbol:26928/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" urn="urn:adsk.eagle:component:26957/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
<class number="1" name="supply" width="0.381" drill="0">
</class>
</classes>
<parts>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="DINA4_L" device=""/>
<part name="EN1" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN2" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN3" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN4" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN5" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN6" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN7" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="EN8" library="misc" library_urn="urn:adsk.eagle:library:17210741" deviceset="ENCODER" device="" package3d_urn="urn:adsk.eagle:package:17210756/4"/>
<part name="X1" library="con-panduit" library_urn="urn:adsk.eagle:library:169" deviceset="057-026-" device="1" package3d_urn="urn:adsk.eagle:package:9202/1"/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+14" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+15" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+16" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="P+17" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="181.61" y="27.94" size="3.302" layer="94">Encoder Board (c) lunOptics 2020</text>
<text x="163.83" y="6.35" size="3.302" layer="94">20200210LN01</text>
<text x="251.46" y="6.35" size="3.302" layer="94">01</text>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="162.56" y="0" smashed="yes">
<attribute name="LAST_DATE_TIME" x="175.26" y="1.27" size="2.54" layer="94"/>
<attribute name="SHEET" x="248.92" y="1.27" size="2.54" layer="94"/>
<attribute name="DRAWING_NAME" x="180.34" y="19.05" size="2.54" layer="94"/>
</instance>
<instance part="EN1" gate="G$1" x="62.23" y="129.54" smashed="yes" rot="MR270">
<attribute name="NAME" x="55.245" y="137.795" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="EN2" gate="G$1" x="62.23" y="110.49" smashed="yes" rot="MR270">
<attribute name="NAME" x="55.245" y="118.745" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="EN3" gate="G$1" x="62.23" y="91.44" smashed="yes" rot="MR270">
<attribute name="NAME" x="55.245" y="99.695" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="EN4" gate="G$1" x="62.23" y="72.39" smashed="yes" rot="MR270">
<attribute name="NAME" x="55.245" y="83.185" size="1.27" layer="95" rot="MR270"/>
<attribute name="VALUE" x="70.485" y="67.31" size="1.27" layer="96" rot="MR270"/>
</instance>
<instance part="EN5" gate="G$1" x="105.41" y="129.54" smashed="yes" rot="MR270">
<attribute name="NAME" x="98.425" y="137.795" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="EN6" gate="G$1" x="105.41" y="110.49" smashed="yes" rot="MR270">
<attribute name="NAME" x="98.425" y="118.745" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="EN7" gate="G$1" x="105.41" y="91.44" smashed="yes" rot="MR270">
<attribute name="NAME" x="98.425" y="99.695" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="EN8" gate="G$1" x="105.41" y="72.39" smashed="yes" rot="MR270">
<attribute name="NAME" x="98.425" y="80.645" size="1.27" layer="95" rot="MR180"/>
</instance>
<instance part="X1" gate="-1" x="76.2" y="132.08" smashed="yes">
<attribute name="NAME" x="77.216" y="131.318" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-2" x="76.2" y="127" smashed="yes">
<attribute name="NAME" x="77.216" y="126.238" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-3" x="48.26" y="132.08" smashed="yes" rot="R180">
<attribute name="NAME" x="47.244" y="132.842" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-4" x="76.2" y="113.03" smashed="yes">
<attribute name="NAME" x="77.216" y="112.268" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-5" x="76.2" y="107.95" smashed="yes">
<attribute name="NAME" x="77.216" y="107.188" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-6" x="48.26" y="113.03" smashed="yes" rot="R180">
<attribute name="NAME" x="47.244" y="113.792" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-7" x="76.2" y="93.98" smashed="yes">
<attribute name="NAME" x="77.216" y="93.218" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-8" x="76.2" y="88.9" smashed="yes">
<attribute name="NAME" x="77.216" y="88.138" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-9" x="48.26" y="93.98" smashed="yes" rot="R180">
<attribute name="NAME" x="47.244" y="94.742" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-10" x="76.2" y="74.93" smashed="yes">
<attribute name="NAME" x="77.216" y="74.168" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-11" x="76.2" y="69.85" smashed="yes">
<attribute name="NAME" x="77.216" y="69.088" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-12" x="48.26" y="74.93" smashed="yes" rot="R180">
<attribute name="NAME" x="47.244" y="75.692" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-13" x="119.38" y="132.08" smashed="yes">
<attribute name="NAME" x="120.396" y="131.318" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-14" x="119.38" y="127" smashed="yes">
<attribute name="NAME" x="120.396" y="126.238" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-15" x="91.44" y="132.08" smashed="yes" rot="R180">
<attribute name="NAME" x="90.424" y="132.842" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-16" x="119.38" y="113.03" smashed="yes">
<attribute name="NAME" x="120.396" y="112.268" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-17" x="119.38" y="107.95" smashed="yes">
<attribute name="NAME" x="120.396" y="107.188" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-18" x="91.44" y="113.03" smashed="yes" rot="R180">
<attribute name="NAME" x="90.424" y="113.792" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-19" x="119.38" y="93.98" smashed="yes">
<attribute name="NAME" x="120.396" y="93.218" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-20" x="119.38" y="88.9" smashed="yes">
<attribute name="NAME" x="120.396" y="88.138" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-21" x="91.44" y="93.98" smashed="yes" rot="R180">
<attribute name="NAME" x="90.424" y="94.742" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-22" x="119.38" y="74.93" smashed="yes">
<attribute name="NAME" x="120.396" y="74.168" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-23" x="119.38" y="69.85" smashed="yes">
<attribute name="NAME" x="120.396" y="69.088" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-24" x="91.44" y="74.93" smashed="yes" rot="R180">
<attribute name="NAME" x="90.424" y="75.692" size="1.524" layer="95" rot="R180"/>
</instance>
<instance part="X1" gate="-25" x="60.96" y="53.34" smashed="yes">
<attribute name="NAME" x="61.976" y="52.578" size="1.524" layer="95"/>
</instance>
<instance part="X1" gate="-26" x="60.96" y="45.72" smashed="yes">
<attribute name="NAME" x="61.976" y="44.958" size="1.524" layer="95"/>
</instance>
<instance part="P+1" gate="VCC" x="77.47" y="129.54" smashed="yes" rot="R270"/>
<instance part="P+2" gate="VCC" x="48.26" y="127" smashed="yes" rot="R90">
<attribute name="VALUE" x="50.8" y="124.46" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+3" gate="VCC" x="48.26" y="107.95" smashed="yes" rot="R90">
<attribute name="VALUE" x="50.8" y="105.41" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+4" gate="VCC" x="48.26" y="88.9" smashed="yes" rot="R90">
<attribute name="VALUE" x="50.8" y="86.36" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+5" gate="VCC" x="48.26" y="69.85" smashed="yes" rot="R90">
<attribute name="VALUE" x="50.8" y="67.31" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+6" gate="VCC" x="91.44" y="69.85" smashed="yes" rot="R90">
<attribute name="VALUE" x="93.98" y="67.31" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+7" gate="VCC" x="91.44" y="88.9" smashed="yes" rot="R90">
<attribute name="VALUE" x="93.98" y="86.36" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+8" gate="VCC" x="91.44" y="107.95" smashed="yes" rot="R90">
<attribute name="VALUE" x="93.98" y="105.41" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+9" gate="VCC" x="91.44" y="127" smashed="yes" rot="R90">
<attribute name="VALUE" x="93.98" y="124.46" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="P+10" gate="VCC" x="76.2" y="110.49" smashed="yes" rot="R270"/>
<instance part="P+11" gate="VCC" x="76.2" y="91.44" smashed="yes" rot="R270"/>
<instance part="P+12" gate="VCC" x="76.2" y="72.39" smashed="yes" rot="R270"/>
<instance part="P+13" gate="VCC" x="119.38" y="72.39" smashed="yes" rot="R270"/>
<instance part="P+14" gate="VCC" x="119.38" y="91.44" smashed="yes" rot="R270"/>
<instance part="P+15" gate="VCC" x="119.38" y="110.49" smashed="yes" rot="R270"/>
<instance part="P+16" gate="VCC" x="116.84" y="129.54" smashed="yes" rot="R270"/>
<instance part="P+17" gate="VCC" x="48.26" y="53.34" smashed="yes" rot="R90">
<attribute name="VALUE" x="50.8" y="50.8" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND1" gate="1" x="49.53" y="43.18" smashed="yes">
<attribute name="VALUE" x="46.99" y="40.64" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="X1" gate="-1" pin="S"/>
<pinref part="EN1" gate="G$1" pin="A"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="X1" gate="-2" pin="S"/>
<pinref part="EN1" gate="G$1" pin="C"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="X1" gate="-3" pin="S"/>
<pinref part="EN1" gate="G$1" pin="S1"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="EN2" gate="G$1" pin="A"/>
<pinref part="X1" gate="-4" pin="S"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="EN2" gate="G$1" pin="C"/>
<pinref part="X1" gate="-5" pin="S"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="EN2" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-6" pin="S"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="EN3" gate="G$1" pin="A"/>
<pinref part="X1" gate="-7" pin="S"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="EN3" gate="G$1" pin="C"/>
<pinref part="X1" gate="-8" pin="S"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="EN3" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-9" pin="S"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="EN4" gate="G$1" pin="A"/>
<pinref part="X1" gate="-10" pin="S"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="EN4" gate="G$1" pin="C"/>
<pinref part="X1" gate="-11" pin="S"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="EN4" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-12" pin="S"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="EN5" gate="G$1" pin="A"/>
<pinref part="X1" gate="-13" pin="S"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="EN5" gate="G$1" pin="C"/>
<pinref part="X1" gate="-14" pin="S"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="EN5" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-15" pin="S"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="EN6" gate="G$1" pin="A"/>
<pinref part="X1" gate="-16" pin="S"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="EN6" gate="G$1" pin="C"/>
<pinref part="X1" gate="-17" pin="S"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="EN6" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-18" pin="S"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="EN7" gate="G$1" pin="A"/>
<pinref part="X1" gate="-19" pin="S"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="EN7" gate="G$1" pin="C"/>
<pinref part="X1" gate="-20" pin="S"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="EN7" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-21" pin="S"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="EN8" gate="G$1" pin="A"/>
<pinref part="X1" gate="-22" pin="S"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="EN8" gate="G$1" pin="C"/>
<pinref part="X1" gate="-23" pin="S"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="EN8" gate="G$1" pin="S1"/>
<pinref part="X1" gate="-24" pin="S"/>
</segment>
</net>
<net name="VCC" class="1">
<segment>
<pinref part="EN1" gate="G$1" pin="B"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="74.93" y1="129.54" x2="71.12" y2="129.54" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN1" gate="G$1" pin="S2"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
<wire x1="50.8" y1="127" x2="53.34" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN2" gate="G$1" pin="S2"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
<wire x1="50.8" y1="107.95" x2="53.34" y2="107.95" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN3" gate="G$1" pin="S2"/>
<pinref part="P+4" gate="VCC" pin="VCC"/>
<wire x1="50.8" y1="88.9" x2="53.34" y2="88.9" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN4" gate="G$1" pin="S2"/>
<pinref part="P+5" gate="VCC" pin="VCC"/>
<wire x1="50.8" y1="69.85" x2="53.34" y2="69.85" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN8" gate="G$1" pin="S2"/>
<pinref part="P+6" gate="VCC" pin="VCC"/>
<wire x1="93.98" y1="69.85" x2="96.52" y2="69.85" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN7" gate="G$1" pin="S2"/>
<pinref part="P+7" gate="VCC" pin="VCC"/>
<wire x1="93.98" y1="88.9" x2="96.52" y2="88.9" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN6" gate="G$1" pin="S2"/>
<pinref part="P+8" gate="VCC" pin="VCC"/>
<wire x1="93.98" y1="107.95" x2="96.52" y2="107.95" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN5" gate="G$1" pin="S2"/>
<pinref part="P+9" gate="VCC" pin="VCC"/>
<wire x1="93.98" y1="127" x2="96.52" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN2" gate="G$1" pin="B"/>
<pinref part="P+10" gate="VCC" pin="VCC"/>
<wire x1="73.66" y1="110.49" x2="71.12" y2="110.49" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN3" gate="G$1" pin="B"/>
<pinref part="P+11" gate="VCC" pin="VCC"/>
<wire x1="73.66" y1="91.44" x2="71.12" y2="91.44" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN4" gate="G$1" pin="B"/>
<pinref part="P+12" gate="VCC" pin="VCC"/>
<wire x1="73.66" y1="72.39" x2="71.12" y2="72.39" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN8" gate="G$1" pin="B"/>
<pinref part="P+13" gate="VCC" pin="VCC"/>
<wire x1="116.84" y1="72.39" x2="114.3" y2="72.39" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN7" gate="G$1" pin="B"/>
<pinref part="P+14" gate="VCC" pin="VCC"/>
<wire x1="116.84" y1="91.44" x2="114.3" y2="91.44" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN6" gate="G$1" pin="B"/>
<pinref part="P+15" gate="VCC" pin="VCC"/>
<wire x1="116.84" y1="110.49" x2="114.3" y2="110.49" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="EN5" gate="G$1" pin="B"/>
<pinref part="P+16" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="X1" gate="-25" pin="S"/>
<pinref part="P+17" gate="VCC" pin="VCC"/>
<wire x1="50.8" y1="53.34" x2="55.88" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="1">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<pinref part="X1" gate="-26" pin="S"/>
<wire x1="49.53" y1="45.72" x2="55.88" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
