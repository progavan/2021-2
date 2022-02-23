default:
	@echo "Use make menuconfig para configurar el proyecto"
menuconfig:
	kconfig-mconf Kconfig   # sudo apt-get install kconfig-frontends-nox
	./scripts/kconfig/conf --silentoldconfig Kconfig
	rm -v obj/Release/*.o

