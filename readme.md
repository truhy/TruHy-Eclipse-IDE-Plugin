# TruHy Embedded C/C++ Tools (Eclipse IDE plugin)

## Overview

An Eclipse IDE plugin to provide New Project Wizards for the "Intel Cyclone V SoC FPGA" series chipset.  It is intended for the DE10-Nano FPGA development board.  This enables developers to easily create Eclipse IDE C projects that are pre-configured.

## The folders

| Folder                                      | Description                                            |
| --------------------------------------------| ------------------------------------------------------ |
| truhy_intel_socfpga_plugin                  | Eclipse IDE plugin project                             |
| truhy_intel_socfpga_feature                 | Eclipse IDE feature project                            |
| repository                                  | A built installable plugin                             |
| truhy_intel_socfpga_plugin_separate_configs | Bad (due to CDT plugin bug) Eclipse IDE plugin project |

Note:

There seems to be a bug in the CDT template extension point "org.eclipse.cdt.managedbuilder.core.buildDefinitions" and "parent" attribute of "configuration" tag.  The bug causes the "parent" attribute to be regenerated from the value of the "id" attribute.  This prevents new plugins (via CDT xml templates) creating valid new custom build configurations, e.g. DebugBySemihosting and DebugByUART

The bad project demonstrates this bug.

## How to install the custom Eclipse IDE plugin

1. Visit [Eclipse IDE website](https://www.eclipse.org/downloads/) and download the installer and install "Eclipse IDE for Embedded C/C++ Developers"
2. In Eclipse IDE, use the "Install New Software..." to install the plugin.

See my tutorial at:
[https://truhy.co.uk](https://truhy.co.uk)

## Run-time dependencies

Plugin minimum requirements:
- JavaSE-11 or later
- CDT & Embedded CDT plugins

## Information for developers

## How to edit the plugin source code

1. Download code as zip from Github, extract all to a folder of your choice
2. Go to Eclipse IDE website to find how to install "Eclipse IDE for Embedded C/C++ Developers"
3. Use the "Install New Software..." to install the "Eclipse Plug-in Development Environment" plugin.
4. Open the source code plugin Eclipse IDE project from folder "truhy_intel_socfpga_plugin"
5. Open the source code feature Eclipse IDE project from folder "truhy_intel_socfpga_feature"

## How to debug (run) without installing the plugin

1. From the menu select "Run/Debug Configurations..."
2. Open tree of "Eclipse Application"
3. Select the pre-made debug configuration "Debug Plugin Template"
4. Click the "Debug" button

A new window should appear, running a new instance of Eclipse IDE containing the plugin, now you can test it.

## How to export (build) the plugin

After making your changes, you will need to export the plugin, this will produce files that are installable (deployable).  Surprisingly, exporting from the plugin project as a deployable plugin is useless.  This is because in later versions of Eclipse IDE, plugins can only install from a P2 Equinox repository.

Steps to export a deployable plugin as a repository:
1. Open both projects plugin & feature in Eclipse IDE
2. In the feature project select from the menu "File/Export..."
3. In the dialog, select "Deployable Features"
4. Select your preferred destination
5. Go to "Options" tab, check "Categorize repository" and browse the category.xml file so that the path is updated to your local drive
6. Click "Finish" button

*It is important the file location in step 5 is correct, currently Eclipse does not check whether the file exists, if not, it silently ignores it!  A bug?
The problem with this is that the deployed plugin will not appear in the install dialog, because it does not have a category!!

I have place a few images inside the images folder showing some of the steps.

## Helpful references

Eclipse documentation:
- [How to add project templates to CDT](https://help.eclipse.org/2023-06/index.jsp?topic=%2Forg.eclipse.cdt.doc.isv%2Fguide%2FprojectTemplateEngine%2FHowtodeveloptemplates.html&anchor=howto%2edevelop%2etemplates)
- [What's New in CDT Build System 4.0](https://help.eclipse.org/2023-06/index.jsp?topic=%2Forg.eclipse.cdt.doc.isv%2Fguide%2Fcdt_build_system%2Fwhats_new%2F4.0%2Fwhats_new_CBS_40.html&cp%3D13_0_3)

Useful source codes:
- [CDT processes source code](https://github.com/eclipse-cdt/cdt/tree/main/core/org.eclipse.cdt.core/templateengine/org/eclipse/cdt/core/templateengine/process/processes)
- [Embed CDT templates](https://github.com/eclipse-embed-cdt/eclipse-plugins/tree/master/plugins)
- [Embed CDT processes](https://github.com/eclipse-embed-cdt/eclipse-plugins/tree/master/plugins/org.eclipse.embedcdt.templates.core/src/org/eclipse/embedcdt/templates/core/processes)
