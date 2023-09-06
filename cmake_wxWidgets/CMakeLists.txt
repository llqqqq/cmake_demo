cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_wxWisgets VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set (WX_LIB "D:/source_code/wxWidgets/wxWidgets-3.1.5/lib/vc_x64_lib")
set (WX_INCLUDE "D:/source_code/wxWidgets/wxWidgets-3.0.5-headers/include")

include_directories(${WX_INCLUDE})
include_directories(${WX_LIB}/mswu)

# wxbase31u.lib
add_library(wxbase31u STATIC IMPORTED)
set_target_properties(wxbase31u PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxbase31u.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxbase31ud.lib"
    #INTERFACE_INCLUDE_DIRECTORIES "${WX_INCLUDE}"
)

# wxbase31u_net.lib
add_library(wxbase31u_net STATIC IMPORTED)
set_target_properties(wxbase31u_net PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxbase31u_net.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxbase31ud_net.lib"
)

# wxbase31u_xml.lib
add_library(wxbase31u_xml STATIC IMPORTED)
set_target_properties(wxbase31u_xml PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxbase31u_xml.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxbase31ud_xml.lib"
)

# wxmsw31u_adv.lib
add_library(wxmsw31u_adv STATIC IMPORTED)
set_target_properties(wxmsw31u_adv PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_adv.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_adv.lib"
)

# wxmsw31u_aui.lib
add_library(wxmsw31u_aui STATIC IMPORTED)
set_target_properties(wxmsw31u_aui PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_aui.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_aui.lib"
)

# wxmsw31u_core.lib
add_library(wxmsw31u_core STATIC IMPORTED)
set_target_properties(wxmsw31u_core PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_core.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_core.lib"
)

# wxmsw31u_gl.lib
add_library(wxmsw31u_gl STATIC IMPORTED)
set_target_properties(wxmsw31u_gl PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_gl.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_gl.lib"
)

# wxmsw31u_html.lib
add_library(wxmsw31u_html STATIC IMPORTED)
set_target_properties(wxmsw31u_html PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_html.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_html.lib"
)

# wxmsw31u_media.lib
add_library(wxmsw31u_media STATIC IMPORTED)
set_target_properties(wxmsw31u_media PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_media.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_media.lib"
)

# wxmsw31u_propgrid.lib
add_library(wxmsw31u_propgrid STATIC IMPORTED)
set_target_properties(wxmsw31u_propgrid PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_propgrid.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_propgrid.lib"
)

# wxmsw31u_qa.lib
add_library(wxmsw31u_qa STATIC IMPORTED)
set_target_properties(wxmsw31u_qa PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_qa.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_qa.lib"
)

# wxmsw31u_ribbon.lib
add_library(wxmsw31u_ribbon STATIC IMPORTED)
set_target_properties(wxmsw31u_ribbon PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_ribbon.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_ribbon.lib"
)

# wxmsw31u_richtext.lib
add_library(wxmsw31u_richtext STATIC IMPORTED)
set_target_properties(wxmsw31u_richtext PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_richtext.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_richtext.lib"
)

# wxmsw31u_stc.lib
add_library(wxmsw31u_stc STATIC IMPORTED)
set_target_properties(wxmsw31u_stc PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_stc.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_stc.lib"
)

# wxmsw31u_webview.lib
add_library(wxmsw31u_webview STATIC IMPORTED)
set_target_properties(wxmsw31u_webview PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_webview.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_webview.lib"
)

# wxmsw31u_xrc.lib
add_library(wxmsw31u_xrc STATIC IMPORTED)
set_target_properties(wxmsw31u_xrc PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxmsw31u_xrc.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxmsw31ud_xrc.lib"
)

# wxexpat.lib
add_library(wxexpat STATIC IMPORTED)
set_target_properties(wxexpat PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxexpat.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxexpatd.lib"
)

# wxjpeg.lib
add_library(wxjpeg STATIC IMPORTED)
set_target_properties(wxjpeg PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxjpeg.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxjpegd.lib"
)

# wxpng.lib
add_library(wxpng STATIC IMPORTED)
set_target_properties(wxpng PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxpng.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxpngd.lib"
)

# wxregexu.lib
add_library(wxregexu STATIC IMPORTED)
set_target_properties(wxregexu PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxregexu.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxregexud.lib"
)

# wxscintilla.lib
add_library(wxscintilla STATIC IMPORTED)
set_target_properties(wxscintilla PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxscintilla.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxscintillad.lib"
)

# wxtiff.lib
add_library(wxtiff STATIC IMPORTED)
set_target_properties(wxtiff PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxtiff.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxtiffd.lib"
)

# wxzlib.lib
add_library(wxzlib STATIC IMPORTED)
set_target_properties(wxzlib PROPERTIES
    IMPORTED_LOCATION_RELEASE     "${WX_LIB}/wxzlib.lib"
    IMPORTED_LOCATION_DEBUG       "${WX_LIB}/wxzlibd.lib"
)

set (WXLIBS 
    wxbase31u.lib
    wxbase31u_net.lib
    wxbase31u_xml.lib
    wxmsw31u_adv.lib
    wxmsw31u_aui.lib
    wxmsw31u_core.lib
    wxmsw31u_gl.lib
    wxmsw31u_html.lib
    wxmsw31u_media.lib
    wxmsw31u_propgrid.lib
    wxmsw31u_qa.lib
    wxmsw31u_ribbon.lib
    wxmsw31u_richtext.lib
    wxmsw31u_stc.lib
    wxmsw31u_webview.lib
    wxmsw31u_xrc.lib
    wxexpat.lib
    wxjpeg.lib
    wxpng.lib
    wxregexu.lib
    wxscintilla.lib
    wxtiff.lib
    wxzlib.lib
)

add_subdirectory(src)