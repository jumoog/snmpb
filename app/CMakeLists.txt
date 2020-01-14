set(GUI_SOURCES
    agent.cpp
    agent.h
    agentprofile.cpp
    agentprofile.h
    agentprofile.ui
    comboboxes.cpp
    comboboxes.h
    discovery.cpp
    discovery.h
    find.ui
    gotoline.ui
    graph.cpp
    graph.h
    logsnmpb.cpp
    logsnmpb.h
    main.cpp
    mainw.ui
    markerwidget.cpp
    markerwidget.h
    mibeditor.cpp
    mibeditor.h
    mibhighlighter.cpp
    mibhighlighter.h
    mibmodule.cpp
    mibmodule.h
    mibnode.cpp
    mibnode.h
    mibselection.cpp
    mibselection.h
    mibtextedit.cpp
    mibtextedit.h
    mibview.cpp
    mibview.h
    plot.ui
    preferences.cpp
    preferences.h
    preferences.ui
    replace.ui
    snmpbapp.h
    snmpb.cpp
    snmpb.h
    trap.cpp
    trap.h
    usmprofile.cpp
    usmprofile.h
    usmprofile.ui
    varbinds.ui
    )

add_executable(snmpb ${GUI_SOURCES})
target_link_libraries(snmpb
    Qt5::Widgets
    qwt
    snmpxx
    tomcrypt
    libsmi
    )
set_target_properties(snmpb PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    )
target_include_directories(snmpb PRIVATE ${SnmpB_SOURCE_DIR}/app)
