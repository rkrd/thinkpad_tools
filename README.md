# thinkpad_tools
backlight: To be used with acpi handler:
```bash
#!/bin/sh
# Default acpi script that takes an entry for all actions

IFS=${IFS}/
set $@

case "$1" in
    button)
        case "$2" in
        power) /sbin/init 0
        ;;
        lid) [ "$4" = "close" ] && /usr/sbin/pm-suspend
        ;;
        *) logger "ACPI action $2 is not defined"
        ;;
        esac
        ;;
        video)
        case "$2" in
        brightnessup) /usr/local/sbin/backlight u
        ;;
        brightnessdown) /usr/local/sbin/backlight d
        ;;
    esac
    ;;
    *)
    logger "ACPI group $1 / action $2 is not defined"
    ;;
esac
```

kbdlight: To be used with root suid to let user control /proc/apci/ibm/kbdlight via commands.

