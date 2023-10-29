.pragma library

var dayNames = ["一", "二", "三", "四", "五", "六", "日"]

function timeTxt(i) {
	if (i < 10)
		return "" + 0 + i
	return "" + i
}

function setBit(num, i, val) {
	if (val !== 1 && val !== 0)
		throw "Val should be 0 or 1"
	return ((num | (1 << i)) ^ (1 << i)) | (val << i)
}

function getBit(num, i) {
	return (num & (1 << i)) >> i
}
