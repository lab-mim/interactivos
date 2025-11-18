{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 19.0, 44.0, 1838.0, 1060.0 ],
		"bglocked" : 0,
		"defrect" : [ 19.0, 44.0, 1838.0, 1060.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "jit.pwindow",
					"numoutlets" : 2,
					"patching_rect" : [ 1563.0, 512.0, 59.539349, 282.0 ],
					"id" : "obj-14",
					"outlettype" : [ "", "" ],
					"onscreen" : 0,
					"presentation_rect" : [ 1563.0, 501.0, 110.0, 521.0 ],
					"numinlets" : 1,
					"depthbuffer" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read dozer.mov",
					"numoutlets" : 1,
					"patching_rect" : [ 458.0, 101.0, 73.0, 15.0 ],
					"id" : "obj-39",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 9.0,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "press \"tab\" to start",
					"numoutlets" : 0,
					"patching_rect" : [ 4.0, 242.746674, 168.0, 28.0 ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"fontsize" : 18.314985,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "splitting ",
					"numoutlets" : 0,
					"patching_rect" : [ 401.0, 487.746674, 151.0, 28.0 ],
					"id" : "obj-23",
					"fontname" : "Arial",
					"fontsize" : 18.314985,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "part of hd 720p",
					"numoutlets" : 0,
					"patching_rect" : [ 421.0, 340.746674, 151.0, 28.0 ],
					"id" : "obj-19",
					"fontname" : "Arial",
					"fontsize" : 18.314985,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "hd 720p",
					"numoutlets" : 0,
					"patching_rect" : [ 433.0, 159.746674, 214.0, 28.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"fontsize" : 18.314985,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "--> gradient softedge generator",
					"linecount" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 1184.0, 4.746666, 214.0, 49.0 ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"fontsize" : 18.314985,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "--> \"softedge area\"",
					"numoutlets" : 0,
					"patching_rect" : [ 1444.0, 165.0, 150.0, 20.0 ],
					"id" : "obj-7",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "--> \"all the rest area\"",
					"numoutlets" : 0,
					"patching_rect" : [ 881.0, 189.0, 150.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b b",
					"numoutlets" : 2,
					"patching_rect" : [ 1079.0, 70.0, 34.0, 20.0 ],
					"id" : "obj-42",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r load",
					"numoutlets" : 1,
					"patching_rect" : [ 317.0, 56.0, 41.0, 20.0 ],
					"id" : "obj-38",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "7",
					"numoutlets" : 1,
					"patching_rect" : [ 1395.0, 83.0, 32.5, 18.0 ],
					"id" : "obj-37",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"numoutlets" : 2,
					"patching_rect" : [ 1400.0, 111.0, 50.0, 20.0 ],
					"id" : "obj-35",
					"fontname" : "Arial",
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.pwindow",
					"numoutlets" : 2,
					"patching_rect" : [ 1497.0, 497.0, 59.539349, 282.0 ],
					"id" : "obj-15",
					"outlettype" : [ "", "" ],
					"onscreen" : 0,
					"presentation_rect" : [ 1442.0, 732.0, 110.0, 521.0 ],
					"numinlets" : 1,
					"depthbuffer" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "preset",
					"numoutlets" : 4,
					"patching_rect" : [ 1059.0, 139.0, 100.0, 40.0 ],
					"id" : "obj-32",
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"numinlets" : 1,
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-157", "flonum", "float", 0.978 ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-157", "flonum", "float", 0.9673 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r load",
					"numoutlets" : 1,
					"patching_rect" : [ 1065.0, 9.0, 41.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1",
					"numoutlets" : 1,
					"patching_rect" : [ 1017.0, 136.0, 32.5, 18.0 ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.render screen2 @ortho 2 @erase_color 0. 0. 0. 1.",
					"numoutlets" : 2,
					"patching_rect" : [ 38.0, 1037.0, 291.0, 20.0 ],
					"id" : "obj-135",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.window screen2 @size 400 300 @pos 1020 100",
					"numoutlets" : 2,
					"patching_rect" : [ 766.0, 1430.0, 271.0, 20.0 ],
					"id" : "obj-134",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix 1 char 695 521",
					"numoutlets" : 2,
					"patching_rect" : [ 1180.0, 463.0, 134.0, 20.0 ],
					"id" : "obj-220",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix soft_l 1 char 695 521 @dstdimstart 586 0 @dstdimend 694 520 @usedstdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 363.0, 688.847839, 481.0, 20.0 ],
					"id" : "obj-218",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 12.141958,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix soft_l 1 char 695 521 @dstdimstart 0 0 @dstdimend 585 520 @usedstdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 391.0, 659.305054, 458.0, 20.0 ],
					"id" : "obj-219",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.87826,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix 1 char 695 521",
					"numoutlets" : 2,
					"patching_rect" : [ 1343.0, 469.0, 134.0, 20.0 ],
					"id" : "obj-217",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read white_mitmitte.jpg",
					"numoutlets" : 1,
					"patching_rect" : [ 361.0, 120.0, 103.0, 15.0 ],
					"id" : "obj-173",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 9.0,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1021.0, 259.342865, 33.0, 15.0 ],
					"id" : "obj-172",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 7.547954,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numoutlets" : 1,
					"patching_rect" : [ 1013.0, 240.0, 17.0, 17.0 ],
					"id" : "obj-171",
					"outlettype" : [ "bang" ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numoutlets" : 1,
					"patching_rect" : [ 1110.0, 223.0, 20.0, 20.0 ],
					"id" : "obj-170",
					"outlettype" : [ "bang" ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pak 0. 0. 0. 0. 0. 0. 0. 0.",
					"numoutlets" : 1,
					"patching_rect" : [ 1513.0, 304.0, 444.5, 17.0 ],
					"id" : "obj-168",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 9.0,
					"numinlets" : 8
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix softedge 1 char 110 1 @interp 1",
					"numoutlets" : 2,
					"patching_rect" : [ 1283.0, 417.0, 223.0, 20.0 ],
					"id" : "obj-164",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix luma 1 float32 8",
					"numoutlets" : 2,
					"patching_rect" : [ 1279.0, 355.0, 111.0, 17.0 ],
					"id" : "obj-166",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 9.0,
					"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.fill luma 0",
					"numoutlets" : 2,
					"patching_rect" : [ 1289.0, 332.0, 70.0, 17.0 ],
					"id" : "obj-167",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"fontsize" : 9.0,
					"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1041.0, 187.142853, 92.0, 26.0 ],
					"id" : "obj-157",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix soft_r 1 char 695 521 @dstdimstart 109 0 @dstdimend 694 520 @usedstdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 830.0, 793.847839, 483.0, 20.0 ],
					"id" : "obj-153",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 12.141958,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix soft_r 1 char 695 521 @dstdimstart 0 0 @dstdimend 108 520 @usedstdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 870.0, 762.305054, 459.0, 20.0 ],
					"id" : "obj-154",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.87826,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix links 4 char 695 521 @srcdimstart 0 0 @srcdimend 695 521 @usesrcdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 246.0, 531.238464, 397.0, 18.0 ],
					"id" : "obj-142",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 10.425039,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix rechts 4 char 695 521 @srcdimstart 586 0 @srcdimend 1280 521 @usesrcdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 567.0, 504.213867, 431.0, 19.0 ],
					"id" : "obj-143",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 10.596445,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.slab screen2",
					"numoutlets" : 2,
					"patching_rect" : [ 870.0, 947.0, 100.0, 20.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"outlettype" : [ "jit_gl_texture", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r load",
					"numoutlets" : 1,
					"patching_rect" : [ 512.0, 773.0, 41.0, 20.0 ],
					"id" : "obj-243",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1",
					"numoutlets" : 1,
					"patching_rect" : [ 506.0, 802.0, 32.5, 18.0 ],
					"id" : "obj-242",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "umenu",
					"numoutlets" : 3,
					"patching_rect" : [ 504.0, 829.0, 81.0, 20.0 ],
					"types" : [  ],
					"id" : "obj-124",
					"fontname" : "Arial",
					"outlettype" : [ "int", "", "" ],
					"fontsize" : 11.595187,
					"items" : [ "pass", ",", "mult", ",", "div", ",", "add", ",", "sub", ",", "mod", ",", "min", ",", "max", ",", "abs", ",", "avg", ",", "absdiff", ",", "and", ",", "or", ",", "xor", ",", "not", ",", "gt", ",", "lt", ",", "gte", ",", "lte", ",", "eq", ",", "neq", ",", "gtp", ",", "ltp", ",", "gtep", ",", "ltep", ",", "eqp", ",", "neqp", ",", "sin", ",", "cos", ",", "tan", ",", "asin", ",", "acos", ",", "atan", ",", "atan2", ",", "sinh", ",", "cosh", ",", "tanh", ",", "asinh", ",", "acosh", ",", "atanh", ",", "exp", ",", "exp2", ",", "ln", ",", "log2", ",", "log10", ",", "hypot", ",", "pow", ",", "sqrt", ",", "ceil", ",", "floor", ",", "fract", ",", "normsin", ",", "normcos" ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "sprintf read op.%s.jxs",
					"numoutlets" : 1,
					"patching_rect" : [ 496.0, 872.0, 121.0, 20.0 ],
					"id" : "obj-140",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.slab screen1",
					"numoutlets" : 2,
					"patching_rect" : [ 436.0, 912.0, 100.0, 20.0 ],
					"id" : "obj-141",
					"fontname" : "Arial",
					"outlettype" : [ "jit_gl_texture", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix luma2 1 float32 1",
					"numoutlets" : 2,
					"patching_rect" : [ 1071.0, 312.0, 116.0, 17.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 9.0,
					"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.fill luma2 0",
					"numoutlets" : 2,
					"patching_rect" : [ 1048.0, 277.0, 63.0, 17.0 ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"fontsize" : 9.0,
					"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1701.0, 230.142853, 55.0, 26.0 ],
					"id" : "obj-108",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1633.0, 230.142853, 55.0, 26.0 ],
					"id" : "obj-112",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1567.0, 230.142853, 55.0, 26.0 ],
					"id" : "obj-120",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix softedge2 1 char 110 1 @interp 1",
					"numoutlets" : 2,
					"patching_rect" : [ 1522.0, 423.0, 229.0, 20.0 ],
					"id" : "obj-40",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1505.0, 229.142853, 55.0, 26.0 ],
					"id" : "obj-36",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1437.0, 229.142853, 55.0, 26.0 ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clearall",
					"numoutlets" : 1,
					"patching_rect" : [ 1274.0, 104.0, 47.0, 18.0 ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "preset",
					"numoutlets" : 4,
					"patching_rect" : [ 1266.0, 133.0, 100.0, 40.0 ],
					"id" : "obj-31",
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"numinlets" : 1,
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-108", "flonum", "float", 1.0, 5, "obj-112", "flonum", "float", 0.96, 5, "obj-120", "flonum", "float", 0.86, 5, "obj-36", "flonum", "float", 0.76, 5, "obj-34", "flonum", "float", 0.63, 5, "obj-28", "flonum", "float", 0.51, 5, "obj-44", "flonum", "float", 0.34, 5, "obj-45", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-108", "flonum", "float", 0.73, 5, "obj-112", "flonum", "float", 0.0, 5, "obj-120", "flonum", "float", 0.73, 5, "obj-36", "flonum", "float", 0.0, 5, "obj-34", "flonum", "float", 0.73, 5, "obj-28", "flonum", "float", 0.0, 5, "obj-44", "flonum", "float", 0.73, 5, "obj-45", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 3,
							"data" : [ 5, "obj-108", "flonum", "float", 1.0, 5, "obj-112", "flonum", "float", 1.0, 5, "obj-120", "flonum", "float", 1.0, 5, "obj-36", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.0, 5, "obj-28", "flonum", "float", 1.0, 5, "obj-44", "flonum", "float", 1.0, 5, "obj-45", "flonum", "float", 1.0 ]
						}
, 						{
							"number" : 4,
							"data" : [ 5, "obj-108", "flonum", "float", 1.0, 5, "obj-112", "flonum", "float", 1.0, 5, "obj-120", "flonum", "float", 0.7, 5, "obj-36", "flonum", "float", 0.65, 5, "obj-34", "flonum", "float", 0.53, 5, "obj-28", "flonum", "float", 0.38, 5, "obj-44", "flonum", "float", 0.24, 5, "obj-45", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 5,
							"data" : [ 5, "obj-108", "flonum", "float", 1.0, 5, "obj-112", "flonum", "float", 0.92, 5, "obj-120", "flonum", "float", 0.83, 5, "obj-36", "flonum", "float", 0.7, 5, "obj-34", "flonum", "float", 0.6, 5, "obj-28", "flonum", "float", 0.41, 5, "obj-44", "flonum", "float", 0.26, 5, "obj-45", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 6,
							"data" : [ 5, "obj-108", "flonum", "float", 1.0, 5, "obj-112", "flonum", "float", 0.93, 5, "obj-120", "flonum", "float", 0.86, 5, "obj-36", "flonum", "float", 0.79, 5, "obj-34", "flonum", "float", 0.61, 5, "obj-28", "flonum", "float", 0.47, 5, "obj-44", "flonum", "float", 0.24, 5, "obj-45", "flonum", "float", 0.11 ]
						}
, 						{
							"number" : 7,
							"data" : [ 5, "obj-108", "flonum", "float", 1.0, 5, "obj-112", "flonum", "float", 0.92, 5, "obj-120", "flonum", "float", 0.83, 5, "obj-36", "flonum", "float", 0.7, 5, "obj-34", "flonum", "float", 0.6, 5, "obj-28", "flonum", "float", 0.41, 5, "obj-44", "flonum", "float", 0.26, 5, "obj-45", "flonum", "float", 0.0 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix luma 1 float32 8",
					"numoutlets" : 2,
					"patching_rect" : [ 1518.0, 361.0, 111.0, 17.0 ],
					"id" : "obj-27",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 9.0,
					"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1371.0, 229.142853, 55.0, 26.0 ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1298.0, 228.142853, 55.0, 26.0 ],
					"id" : "obj-44",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 1230.0, 229.142853, 55.0, 26.0 ],
					"id" : "obj-45",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 17.146967,
					"htextcolor" : [ 0.870588, 0.870588, 0.870588, 1.0 ],
					"numinlets" : 1,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pak 0. 0. 0. 0. 0. 0. 0. 0.",
					"numoutlets" : 1,
					"patching_rect" : [ 1298.0, 269.0, 444.5, 17.0 ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 9.0,
					"numinlets" : 8
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.fill luma 0",
					"numoutlets" : 2,
					"patching_rect" : [ 1528.0, 338.0, 70.0, 17.0 ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"fontsize" : 9.0,
					"color" : [ 1.0, 0.890196, 0.090196, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clear",
					"numoutlets" : 1,
					"patching_rect" : [ 166.0, 128.0, 34.0, 18.0 ],
					"id" : "obj-115",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read raster1280720.jpg",
					"numoutlets" : 1,
					"patching_rect" : [ 373.0, 70.052887, 138.0, 19.0 ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.480097,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "1",
					"numoutlets" : 1,
					"patching_rect" : [ 719.0, 1345.25, 32.5, 18.0 ],
					"id" : "obj-18",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r load",
					"numoutlets" : 1,
					"patching_rect" : [ 729.0, 1281.0, 41.0, 20.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "preset",
					"numoutlets" : 4,
					"patching_rect" : [ 531.0, 1033.0, 100.0, 40.0 ],
					"id" : "obj-137",
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"numinlets" : 1,
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-117", "flonum", "float", 0.0, 5, "obj-113", "flonum", "float", 1.0, 5, "obj-118", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-117", "flonum", "float", -0.4, 5, "obj-113", "flonum", "float", 0.49, 5, "obj-118", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 3,
							"data" : [ 5, "obj-117", "flonum", "float", 0.0, 5, "obj-113", "flonum", "float", 0.7, 5, "obj-118", "flonum", "float", -1.41 ]
						}
, 						{
							"number" : 4,
							"data" : [ 5, "obj-117", "flonum", "float", 0.0, 5, "obj-113", "flonum", "float", 1.0, 5, "obj-118", "flonum", "float", -1.14 ]
						}
, 						{
							"number" : 5,
							"data" : [ 5, "obj-117", "flonum", "float", 0.0, 5, "obj-113", "flonum", "float", 0.7, 5, "obj-118", "flonum", "float", -1.41 ]
						}
, 						{
							"number" : 6,
							"data" : [ 5, "obj-117", "flonum", "float", 0.0, 5, "obj-113", "flonum", "float", 0.7, 5, "obj-118", "flonum", "float", -1.41 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "preset",
					"numoutlets" : 4,
					"patching_rect" : [ 954.0, 1008.0, 100.0, 40.0 ],
					"id" : "obj-136",
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"numinlets" : 1,
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-126", "flonum", "float", 0.0, 5, "obj-131", "flonum", "float", 1.0, 5, "obj-127", "flonum", "float", 0.0 ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-126", "flonum", "float", 0.15, 5, "obj-131", "flonum", "float", 0.71, 5, "obj-127", "flonum", "float", 0.37 ]
						}
, 						{
							"number" : 3,
							"data" : [ 5, "obj-126", "flonum", "float", 0.04, 5, "obj-131", "flonum", "float", 0.704, 5, "obj-127", "flonum", "float", 1.33 ]
						}
, 						{
							"number" : 4,
							"data" : [ 5, "obj-126", "flonum", "float", 0.0, 5, "obj-131", "flonum", "float", 1.0, 5, "obj-127", "flonum", "float", 1.1 ]
						}
, 						{
							"number" : 5,
							"data" : [ 5, "obj-126", "flonum", "float", 0.0436, 5, "obj-131", "flonum", "float", 0.7, 5, "obj-127", "flonum", "float", 1.313 ]
						}
, 						{
							"number" : 6,
							"data" : [ 5, "obj-126", "flonum", "float", 0.039, 5, "obj-131", "flonum", "float", 0.7046, 5, "obj-127", "flonum", "float", 1.31 ]
						}
, 						{
							"number" : 7,
							"data" : [ 5, "obj-126", "flonum", "float", 0.039, 5, "obj-131", "flonum", "float", 0.7046, 5, "obj-127", "flonum", "float", 1.315 ]
						}
, 						{
							"number" : 8,
							"data" : [ 5, "obj-126", "flonum", "float", 0.037, 5, "obj-131", "flonum", "float", 0.7046, 5, "obj-127", "flonum", "float", 1.322 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 1.33",
					"numoutlets" : 1,
					"patching_rect" : [ 857.0, 1046.0, 41.0, 20.0 ],
					"id" : "obj-130",
					"fontname" : "Arial",
					"outlettype" : [ "float" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 896.0, 1018.0, 50.0, 20.0 ],
					"id" : "obj-131",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pak scale 1. 1. 1.",
					"numoutlets" : 1,
					"patching_rect" : [ 884.0, 1076.0, 96.0, 20.0 ],
					"id" : "obj-133",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 4
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 1.33",
					"numoutlets" : 1,
					"patching_rect" : [ 426.0, 1085.0, 41.0, 20.0 ],
					"id" : "obj-129",
					"fontname" : "Arial",
					"outlettype" : [ "float" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 930.433655, 1117.0, 50.0, 20.0 ],
					"id" : "obj-126",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 879.433655, 1117.0, 50.0, 20.0 ],
					"id" : "obj-127",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pak position 0. 0. 0.",
					"numoutlets" : 1,
					"patching_rect" : [ 879.0, 1143.120483, 109.0, 20.0 ],
					"id" : "obj-128",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 4
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 456.0, 1048.0, 50.0, 20.0 ],
					"id" : "obj-113",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pak scale 1. 1. 1.",
					"numoutlets" : 1,
					"patching_rect" : [ 412.0, 1115.0, 96.0, 20.0 ],
					"id" : "obj-114",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 4
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 478.433655, 1149.0, 50.0, 20.0 ],
					"id" : "obj-117",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"numoutlets" : 2,
					"patching_rect" : [ 427.433655, 1149.0, 50.0, 20.0 ],
					"id" : "obj-118",
					"fontname" : "Arial",
					"outlettype" : [ "float", "bang" ],
					"triscale" : 0.9,
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pak position 0. 0. 0.",
					"numoutlets" : 1,
					"patching_rect" : [ 427.0, 1175.120483, 109.0, 20.0 ],
					"id" : "obj-119",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 4
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.matrix cut 4 char 1280 521 @srcdimstart 0 100 @srcdimend 1280 621 @usesrcdim 1",
					"numoutlets" : 2,
					"patching_rect" : [ 328.0, 377.563385, 459.0, 20.0 ],
					"id" : "obj-72",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.534784,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r key",
					"numoutlets" : 1,
					"patching_rect" : [ 594.0, 1261.0, 37.0, 20.0 ],
					"id" : "obj-17",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s key",
					"numoutlets" : 0,
					"patching_rect" : [ 75.0, 146.0, 39.0, 20.0 ],
					"id" : "obj-16",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.render screen1 @ortho 2 @erase_color 0. 0. 0. 1.",
					"numoutlets" : 2,
					"patching_rect" : [ 21.0, 1008.0, 291.0, 20.0 ],
					"id" : "obj-64",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.videoplane screen2 @scale 1.333 1. 1. @blend_enable 1",
					"numoutlets" : 2,
					"patching_rect" : [ 936.0, 1213.0, 329.0, 20.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.videoplane screen1 @scale 1.333 1. 1. @blend_enable 1",
					"numoutlets" : 2,
					"patching_rect" : [ 372.0, 1204.0, 329.0, 20.0 ],
					"id" : "obj-200",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "sel 32",
					"numoutlets" : 2,
					"patching_rect" : [ 14.0, 129.0, 43.0, 20.0 ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "" ],
					"fontsize" : 12.0,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"numoutlets" : 2,
					"patching_rect" : [ 6.0, 102.0, 50.0, 20.0 ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"outlettype" : [ "int", "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "key",
					"numoutlets" : 4,
					"patching_rect" : [ 12.0, 76.0, 59.5, 20.0 ],
					"id" : "obj-8",
					"fontname" : "Arial",
					"outlettype" : [ "int", "int", "int", "int" ],
					"fontsize" : 12.0,
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numoutlets" : 1,
					"patching_rect" : [ 16.0, 17.0, 60.0, 20.0 ],
					"id" : "obj-6",
					"fontname" : "Arial",
					"outlettype" : [ "bang" ],
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s load",
					"numoutlets" : 0,
					"patching_rect" : [ 17.0, 46.0, 43.0, 20.0 ],
					"id" : "obj-2",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "fullscreen $1",
					"numoutlets" : 1,
					"patching_rect" : [ 616.0, 1349.25, 76.0, 18.0 ],
					"id" : "obj-50",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "select 27",
					"numoutlets" : 2,
					"patching_rect" : [ 591.0, 1288.25, 57.0, 20.0 ],
					"id" : "obj-58",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numoutlets" : 1,
					"patching_rect" : [ 616.0, 1319.25, 20.0, 20.0 ],
					"id" : "obj-59",
					"outlettype" : [ "int" ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "floating $1",
					"numoutlets" : 1,
					"patching_rect" : [ 628.260681, 1395.212402, 62.0, 18.0 ],
					"id" : "obj-76",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numoutlets" : 1,
					"patching_rect" : [ 628.260681, 1373.44043, 20.0, 20.0 ],
					"id" : "obj-80",
					"outlettype" : [ "int" ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.window screen1 @size 400 300 @pos 600 100",
					"numoutlets" : 2,
					"patching_rect" : [ 436.0, 1442.0, 265.0, 20.0 ],
					"id" : "obj-51",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b b erase",
					"numoutlets" : 3,
					"patching_rect" : [ 40.0, 849.0, 65.0, 20.0 ],
					"id" : "obj-65",
					"fontname" : "Arial",
					"outlettype" : [ "bang", "bang", "erase" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "qmetro 40",
					"numoutlets" : 1,
					"patching_rect" : [ 46.0, 321.0, 63.0, 20.0 ],
					"id" : "obj-67",
					"fontname" : "Arial",
					"outlettype" : [ "bang" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numoutlets" : 1,
					"patching_rect" : [ 52.0, 272.0, 32.0, 32.0 ],
					"id" : "obj-274",
					"outlettype" : [ "int" ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.fpsgui",
					"numoutlets" : 2,
					"patching_rect" : [ 54.0, 1177.0, 80.0, 36.0 ],
					"id" : "obj-20",
					"fontname" : "Arial",
					"outlettype" : [ "", "" ],
					"fontsize" : 12.0,
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read",
					"numoutlets" : 1,
					"patching_rect" : [ 193.0, 102.0, 32.0, 18.0 ],
					"id" : "obj-109",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "stop",
					"numoutlets" : 1,
					"patching_rect" : [ 266.0, 101.0, 30.0, 18.0 ],
					"id" : "obj-110",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "start",
					"numoutlets" : 1,
					"patching_rect" : [ 231.0, 100.0, 31.0, 18.0 ],
					"id" : "obj-111",
					"fontname" : "Arial",
					"outlettype" : [ "" ],
					"fontsize" : 11.595187,
					"numinlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.qt.movie 1280 720 @autostart 0",
					"numoutlets" : 2,
					"patching_rect" : [ 236.0, 159.0, 187.0, 20.0 ],
					"id" : "obj-116",
					"fontname" : "Arial",
					"outlettype" : [ "jit_matrix", "" ],
					"fontsize" : 11.595187,
					"numinlets" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-50", 0 ],
					"destination" : [ "obj-134", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-76", 0 ],
					"destination" : [ "obj-134", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-50", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-76", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 1 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-116", 0 ],
					"destination" : [ "obj-72", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-72", 0 ],
					"destination" : [ "obj-143", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-72", 0 ],
					"destination" : [ "obj-142", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 1 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-157", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-157", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-164", 0 ],
					"destination" : [ "obj-220", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-219", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-220", 0 ],
					"destination" : [ "obj-218", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-153", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-217", 0 ],
					"destination" : [ "obj-154", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-173", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-171", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-171", 0 ],
					"destination" : [ "obj-172", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-157", 0 ],
					"destination" : [ "obj-172", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-172", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-170", 0 ],
					"destination" : [ "obj-168", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-170", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-157", 0 ],
					"destination" : [ "obj-170", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-168", 7 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-168", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-168", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-168", 4 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-168", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-120", 0 ],
					"destination" : [ "obj-168", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-112", 0 ],
					"destination" : [ "obj-168", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-108", 0 ],
					"destination" : [ "obj-168", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-168", 0 ],
					"destination" : [ "obj-167", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-166", 0 ],
					"destination" : [ "obj-164", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-167", 0 ],
					"destination" : [ "obj-166", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-157", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-22", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-108", 0 ],
					"destination" : [ "obj-29", 7 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-112", 0 ],
					"destination" : [ "obj-29", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-120", 0 ],
					"destination" : [ "obj-29", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-29", 4 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-29", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-29", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-29", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-115", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-80", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-18", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-274", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-274", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-59", 0 ],
					"destination" : [ "obj-50", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-59", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-80", 0 ],
					"destination" : [ "obj-76", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-67", 0 ],
					"destination" : [ "obj-65", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-58", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-109", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-111", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-110", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-117", 0 ],
					"destination" : [ "obj-119", 2 ],
					"hidden" : 0,
					"midpoints" : [ 487.933655, 1171.0, 496.5, 1171.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-113", 0 ],
					"destination" : [ "obj-114", 2 ],
					"hidden" : 0,
					"midpoints" : [ 465.5, 1110.0, 472.833344, 1110.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-118", 0 ],
					"destination" : [ "obj-119", 1 ],
					"hidden" : 0,
					"midpoints" : [ 436.933655, 1171.0, 466.5, 1171.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-127", 0 ],
					"destination" : [ "obj-128", 1 ],
					"hidden" : 0,
					"midpoints" : [ 888.933655, 1139.0, 918.5, 1139.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-126", 0 ],
					"destination" : [ "obj-128", 2 ],
					"hidden" : 0,
					"midpoints" : [ 939.933655, 1139.0, 948.5, 1139.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-113", 0 ],
					"destination" : [ "obj-129", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-131", 0 ],
					"destination" : [ "obj-130", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-131", 0 ],
					"destination" : [ "obj-133", 2 ],
					"hidden" : 0,
					"midpoints" : [ 905.5, 1071.0, 944.833313, 1071.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-129", 0 ],
					"destination" : [ "obj-114", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-130", 0 ],
					"destination" : [ "obj-133", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-136", 0 ],
					"destination" : [ "obj-131", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-136", 0 ],
					"destination" : [ "obj-126", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-136", 0 ],
					"destination" : [ "obj-127", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-137", 0 ],
					"destination" : [ "obj-113", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-137", 0 ],
					"destination" : [ "obj-117", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-137", 0 ],
					"destination" : [ "obj-118", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-120", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-112", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-108", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-243", 0 ],
					"destination" : [ "obj-242", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-242", 0 ],
					"destination" : [ "obj-124", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-124", 1 ],
					"destination" : [ "obj-140", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-140", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-143", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-153", 0 ],
					"destination" : [ "obj-26", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-140", 0 ],
					"destination" : [ "obj-141", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-142", 0 ],
					"destination" : [ "obj-141", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-218", 0 ],
					"destination" : [ "obj-141", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-141", 0 ],
					"destination" : [ "obj-200", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-119", 0 ],
					"destination" : [ "obj-200", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-114", 0 ],
					"destination" : [ "obj-200", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-133", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-128", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-64", 0 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 2 ],
					"destination" : [ "obj-64", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 0 ],
					"destination" : [ "obj-64", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 0 ],
					"destination" : [ "obj-135", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 2 ],
					"destination" : [ "obj-135", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-217", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-42", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
