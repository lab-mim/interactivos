{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 421.0, 44.0, 542.0, 286.0 ],
		"bglocked" : 0,
		"defrect" : [ 421.0, 44.0, 542.0, 286.0 ],
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
					"maxclass" : "flonum",
					"fontsize" : 11.595184,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 424.0, 127.0, 50.0, 18.0 ],
					"fontname" : "Helvetica",
					"id" : "obj-67",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "gamma $1",
					"fontsize" : 11.595184,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 424.0, 148.0, 65.0, 16.0 ],
					"fontname" : "Helvetica",
					"id" : "obj-70",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"fontsize" : 11.595184,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 339.0, 127.0, 50.0, 18.0 ],
					"fontname" : "Helvetica",
					"id" : "obj-60",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "fade $1",
					"fontsize" : 11.595184,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 339.0, 148.0, 49.0, 16.0 ],
					"fontname" : "Helvetica",
					"id" : "obj-63",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"fontsize" : 11.595184,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 242.0, 127.0, 50.0, 18.0 ],
					"fontname" : "Helvetica",
					"id" : "obj-58",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "center $1",
					"fontsize" : 11.595184,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 242.0, 148.0, 59.0, 16.0 ],
					"fontname" : "Helvetica",
					"id" : "obj-55",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "overlap+edgefade for multi-projector images",
					"linecount" : 2,
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 122.0, 30.0, 170.0, 33.0 ],
					"fontname" : "Arial",
					"id" : "obj-35"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "tr.overlap.jxs",
					"fontface" : 1,
					"fontsize" : 23.190374,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 121.0, 0.0, 174.0, 33.0 ],
					"fontname" : "Arial",
					"id" : "obj-34"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.window fa @size 640 240",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 14.0, 120.0, 154.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-29",
					"outlettype" : [ "bang", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 419.0, 249.0, 33.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-28"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.videoplane fa @transform_reset 2 @blend_enable 1",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 213.0, 249.0, 303.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-27",
					"outlettype" : [ "jit_matrix", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.slab fa @file tr.overlap.jxs",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"numoutlets" : 2,
					"patching_rect" : [ 213.0, 218.0, 167.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-26",
					"outlettype" : [ "jit_gl_texture", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "getparamlist",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 241.0, 183.0, 74.0, 18.0 ],
					"fontname" : "Arial",
					"id" : "obj-25",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend param",
					"linecount" : 2,
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 320.0, 182.0, 54.0, 33.0 ],
					"fontname" : "Arial",
					"id" : "obj-24",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 355.0, 43.0, 50.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-10",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "rate $1",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 355.0, 65.0, 47.0, 18.0 ],
					"fontname" : "Arial",
					"id" : "obj-9",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "stop",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 321.0, 65.0, 32.5, 18.0 ],
					"fontname" : "Arial",
					"id" : "obj-8",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "read",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 285.0, 65.0, 34.0, 18.0 ],
					"fontname" : "Arial",
					"id" : "obj-7",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.qt.movie 640 240",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 213.0, 96.0, 111.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-6",
					"outlettype" : [ "jit_matrix", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.gl.render fa @erase_color 0 0 0 1",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 14.0, 96.0, 195.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-5",
					"outlettype" : [ "bang", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t b b erase",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 3,
					"patching_rect" : [ 14.0, 59.0, 65.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-4",
					"outlettype" : [ "bang", "bang", "erase" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"minimum" : 0.5,
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"numoutlets" : 2,
					"patching_rect" : [ 51.0, 13.0, 39.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-3",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "qmetro 2",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"numoutlets" : 1,
					"patching_rect" : [ 14.0, 36.0, 56.0, 20.0 ],
					"fontname" : "Arial",
					"id" : "obj-12",
					"outlettype" : [ "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"patching_rect" : [ 14.0, 13.0, 20.0, 20.0 ],
					"id" : "obj-13",
					"outlettype" : [ "int" ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-26", 1 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [ 370.5, 243.0, 428.5, 243.0 ]
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
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [ 250.5, 207.0, 222.5, 207.0 ]
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
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-5", 0 ],
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
					"source" : [ "obj-70", 0 ],
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
					"source" : [ "obj-55", 0 ],
					"destination" : [ "obj-24", 0 ],
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
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-63", 0 ],
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
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-9", 0 ],
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
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-12", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
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
 ]
	}

}
