OBJECTS = main.o
TARGET = hello

all: $(TARGET)

$(TARGET): $(OBJECTS) mo
	$(CC) -o $@ $(OBJECTS)

POT=locale/helloworld.pot
pot: $(POT)
$(POT): main.c
	@mkdir -p locale/zh_CN/LC_MESSAGES
	xgettext -s -k_ -o $@ $^

po: pot locale/zh_CN/LC_MESSAGES/helloworld.po
locale/zh_CN/LC_MESSAGES/helloworld.po: $(POT)
	if [ ! -f $@ ]; then msginit -i $(POT) -o $@; fi
	msgmerge $@ $< -o locale/temp.po
	mv locale/temp.po $@

mo:: po
mo:: locale/zh_CN/LC_MESSAGES/helloworld.mo
locale/zh_CN/LC_MESSAGES/helloworld.mo: locale/zh_CN/LC_MESSAGES/helloworld.po
	msgfmt -o $@ $<

main.o: version.h

version.h: new_header

new_header:
	@sed -e "s#<version>#$$(git describe --dirty --always)#g" < version.h.in > version.h.tmp
	@if diff -q version.h.tmp version.h >/dev/null 2>&1; then \
		rm version.h.tmp; \
	else \
		echo "version.h.in => version.h" ; \
		mv version.h.tmp version.h; \
	fi

clean:
	rm -f $(TARGET) $(OBJECTS) version.h

.PHONY: all clean

# vim: noet
