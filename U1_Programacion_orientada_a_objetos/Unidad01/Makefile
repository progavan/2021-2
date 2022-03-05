default:
	@echo "Use make menuconfig para configurar el proyecto"
menuconfig:
	kconfig-mconf Kconfig
	./scripts/kconfig/conf --silentoldconfig Kconfig
	find ./obj/ -iname '*.o' -exec rm -v {} \;

