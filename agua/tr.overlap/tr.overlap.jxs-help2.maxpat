{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 316.0, 586.0, 647.0, 348.0 ],
		"bglocked" : 0,
		"defrect" : [ 316.0, 586.0, 647.0, 348.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 11.595187,
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
					"maxclass" : "message",
					"text" : "border 0",
					"outlettype" : [ "" ],
					"patching_rect" : [ 80.0, 164.0, 54.0, 18.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-14",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "pos 1920 0",
					"outlettype" : [ "" ],
					"patching_rect" : [ 48.0, 210.0, 68.0, 18.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-2",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 424.0, 127.0, 50.0, 20.0 ],
					"fontname" : "Helvetica",
					"numinlets" : 1,
					"id" : "obj-67",
					"numoutlets" : 2,
					"fontsize" : 11.595184
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "gamma $1",
					"outlettype" : [ "" ],
					"patching_rect" : [ 424.0, 148.0, 65.0, 18.0 ],
					"fontname" : "Helvetica",
					"numinlets" : 2,
					"id" : "obj-70",
					"numoutlets" : 1,
					"fontsize" : 11.595184
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 339.0, 127.0, 50.0, 20.0 ],
					"fontname" : "Helvetica",
					"numinlets" : 1,
					"id" : "obj-60",
					"numoutlets" : 2,
					"fontsize" : 11.595184
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "fade $1",
					"outlettype" : [ "" ],
					"patching_rect" : [ 339.0, 148.0, 49.0, 18.0 ],
					"fontname" : "Helvetica",
					"numinlets" : 2,
					"id" : "obj-63",
					"numoutlets" : 1,
					"fontsize" : 11.595184
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 242.0, 127.0, 50.0, 20.0 ],
					"fontname" : "Helvetica",
					"numinlets" : 1,
					"id" : "obj-58",
					"numoutlets" : 2,
					"fontsize" : 11.595184
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "center $1",
					"outlettype" : [ "" ],
					"patching_rect" : [ 242.0, 148.0, 59.0, 18.0 ],
					"fontname" : "Helvetica",
					"numinlets" : 2,
					"id" : "obj-55",
					"numoutlets" : 1,
					"fontsize" : 11.595184
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "overlap+edgefade for multi-projector images",
					"linecount" : 2,
					"patching_rect" : [ 122.0, 30.0, 170.0, 33.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-35",
					"numoutlets" : 0,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "tr.overlap.jxs",
					"patching_rect" : [ 121.0, 0.0, 174.0, 33.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-34",
					"numoutlets" : 0,
					"fontface" : 1,
					"fontsize" : 23.190374
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.window fa @size 2048 768",
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 14.0, 120.0, 161.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-29",
					"numoutlets" : 2,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print",
					"patching_rect" : [ 419.0, 249.0, 33.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-28",
					"numoutlets" : 0,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.videoplane fa @transform_reset 2 @blend_enable 1",
					"outlettype" : [ "jit_matrix", "" ],
					"patching_rect" : [ 212.0, 279.0, 303.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-27",
					"numoutlets" : 2,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.slab fa @file tr.overlap.jxs",
					"outlettype" : [ "jit_gl_texture", "" ],
					"patching_rect" : [ 213.0, 218.0, 167.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-26",
					"numoutlets" : 2,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "getparamlist",
					"outlettype" : [ "" ],
					"patching_rect" : [ 241.0, 183.0, 74.0, 18.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-25",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend param",
					"linecount" : 2,
					"outlettype" : [ "" ],
					"patching_rect" : [ 320.0, 182.0, 54.0, 33.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-24",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 355.0, 43.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-10",
					"numoutlets" : 2,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "rate $1",
					"outlettype" : [ "" ],
					"patching_rect" : [ 355.0, 65.0, 47.0, 18.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-9",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "stop",
					"outlettype" : [ "" ],
					"patching_rect" : [ 321.0, 65.0, 32.5, 18.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-8",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read",
					"outlettype" : [ "" ],
					"patching_rect" : [ 285.0, 65.0, 34.0, 18.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-7",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.qt.movie @adapt 1",
					"outlettype" : [ "jit_matrix", "" ],
					"patching_rect" : [ 213.0, 96.0, 120.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-6",
					"numoutlets" : 2,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.render fa @erase_color 0 0 0 1",
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 14.0, 96.0, 195.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-5",
					"numoutlets" : 2,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b b erase",
					"outlettype" : [ "bang", "bang", "erase" ],
					"patching_rect" : [ 14.0, 59.0, 65.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-4",
					"numoutlets" : 3,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 51.0, 13.0, 39.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"id" : "obj-3",
					"numoutlets" : 2,
					"minimum" : 0.5,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "qmetro 2",
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 14.0, 36.0, 56.0, 20.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"id" : "obj-12",
					"numoutlets" : 1,
					"fontsize" : 11.595187
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"outlettype" : [ "int" ],
					"patching_rect" : [ 14.0, 13.0, 20.0, 20.0 ],
					"numinlets" : 1,
					"id" : "obj-13",
					"numoutlets" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 294.5, 91.0, 222.5, 91.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 330.5, 88.0, 222.5, 88.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 364.5, 85.0, 222.5, 85.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 1 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 46.5, 91.0, 222.5, 91.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-12", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-67", 0 ],
					"destination" : [ "obj-70", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-63", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-55", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-55", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-63", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-70", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 2 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [ 69.5, 87.0, 23.5, 87.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [ 250.5, 207.0, 222.5, 207.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [ 329.5, 216.0, 222.5, 216.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 1 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [ 370.5, 243.0, 428.5, 243.0 ]
				}

			}
 ]
	}

}
