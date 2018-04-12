
<script src="https://d3js.org/d3.v4.min.js"></script>
<script src="./datasets.js" type="text/javascript"></script>

<svg width="1200" height="1200"> 
<svg id="sub-grafo-1" x="0" y="0"></svg>
<svg id="sub-grafo-2" x="0" y="600"></svg>
<svg>

<script>

var makeSVG = function() {
  d3.select("#sub-grafo-1").append('circle').attr('cx', 300).attr('cy', 300).attr('r', 300).style("fill", "brown").style("opacity:0.8");
  makeGroup('sub-grafo-1', dataset1, 600, 600);

  d3.select("#sub-grafo-2").append('circle').attr('cx', 300).attr('cy', 300).attr('r', 300).style("fill", "red").style("opacity:0.8");
  makeGroup('sub-grafo-2', dataset2, 600, 600);
}

var makeGroup = function(idSelector, data, width, height) {
  // TODO
  var width = width;
  var height = height;

  // Create somewhere to put the force directed graph
  var svg = d3.selectAll("#"+idSelector);

  // Agregar recursivamente los svgs que tengan que ir adentro de este
  var svg2 = svg.append("svg")
    .append("g");

  var rectWidth = width / 10;
  var rectHeight = height / 10;
  var minDistance = Math.sqrt(rectWidth*rectWidth + rectHeight*rectHeight);
  var node_radius = rectWidth / 2;

  // Set up the simulation and add forces
  var simulation = d3.forceSimulation()
  	.nodes(data.nodes);

  var link_force =  d3.forceLink(data.links)
  	.id(function(d) { return d.id; })
    .distance(minDistance)
    .strength(1);

  var charge_force = d3.forceManyBody()
      .strength(-1000);

  var center_force = d3.forceCenter(width / 2, height / 2);

  simulation
      .force("charge_force", charge_force)
      .force("center_force", center_force)
      .force("links",link_force)
      .force('y', d3.forceY(height / 2).strength(0.10));


  // Add tick instructions:
  simulation.on("tick", tickActions );

  // Add encompassing group for the zoom
  var g = svg.append("g")
      .attr("class", "everything-" + idSelector);

  var div = g.select("body").append("div")
      .attr("class", "tooltip");

  // Arrow-heads
  g.append("defs").selectAll("marker")
        .data(['arrowhead'])
      .enter().append("marker")
        .attr("id", function(d) { return d; })
        .attr("viewBox", "0 -5 10 10")
        .attr("refX", 10)
        .attr("refY", 0)
        .attr("marker-units", "stroke-width")
        .attr("markerWidth", rectWidth / 10)
        .attr("markerHeight", rectHeight / 10)
        .attr("orient", "auto")
      .append("path")
        .attr("d", "M0,-5L10,0L0,5");

  // Draw lines for the links
  var link = g.append("g")
  	.attr("class", "links")
  		.selectAll("line").data(data.links)
  		  .enter()
  		.append("path")
        .attr("class", "link")
  			.attr("stroke-width", 2)
  			  .style("stroke", "#000")
        .attr('marker-end', "url(#arrowhead)");//linkColour

  // Draw rects and texts for the nodes
  var nodes = g.append("g")
  	.attr("class", "nodes");

  var node = nodes.selectAll("node")
  	.data(data.nodes)
  	.enter()
  		.append("g")
      .style("opacity", 0.8 );

  node
  	.on("mouseover", function(d) {
  		d3.select(this).select("rect")
        .style("fill", "red");
  		div.transition()
  			.duration(200);
  		div.html("asdasd")
  			.style("left", (d3.event.pageX) + "px")
  			.style("top", (d3.event.pageY - 28) + "px");
  	})
  	.on("mouseout", function(d) {
  		d3.select(this).select("rect").style("fill", rectColour);
  		div.transition()
  			.duration(500);
  	});


  var rect = node.append("circle")
  		.attr("cx", 0)
  		.attr("cy", 0)
  		//.attr("width", rectWidth)
  		//.attr("height", rectHeight)
  		.attr("r", node_radius)
      .attr("fill", rectColour);

  var textName = node.append("text")
  		.text(function (d) { return d.name; })
  		.attr("y", -15)
  		.style("text-anchor", "middle");

  var textOwned = node.append("text")
  		.text(function (d) { return d.id; })
  		.attr("y", 15)
  		.style("text-anchor", "middle");

  node.attr("transform", function(d) {
      return "translate(" + d.x + "," + d.y + ")"
  });

  // Add drag capabilities
  var drag_handler = d3.drag()
  	.on("start", drag_start)
  	.on("drag", drag_drag)
  	.on("end", drag_end);

  drag_handler(node);

  // Add zoom capabilities
  var zoom_handler = d3.zoom()
      .on("zoom", zoom_actions);

  //zoom_handler(svg);

  /** Functions **/

  function rectColour(d){
  	if(d.person){
  		return "blue";
  	} else {
  		return "pink";
  	}
  }

  // Function to choose the line colour and thickness
  function linkColour(d){
  	return "black";
  }

  // Drag functions
  function drag_start(d) {
   if (!d3.event.active) simulation.alphaTarget(0.3).restart();
      d.fx = d.x;
      d.fy = d.y;
  }

  // Make sure you can't drag the rect outside the box
  function drag_drag(d) {
    d.fx = d3.event.x;
    d.fy = d3.event.y;
  }

  function drag_end(d) {
    if (!d3.event.active) simulation.alphaTarget(0);
    d.fx = null;
    d.fy = null;
  }

  // Zoom functions
  function zoom_actions(){
      g.attr("transform", d3.event.transform)
  }

  function tickActions() {
      // update node positions each tick of the simulation
  	node.attr("transform", function(d) {
  		return "translate(" + d.x + "," + d.y + ")"
  	});
      // update link positions
    link.attr( "d", function(d) {
      // Muevo los limites del path para que conecte los BORDES de los nodos
      diffX = d.target.x - d.source.x;
      diffY = d.target.y - d.source.y;

      // Length of path from center of source node to center of target node
      pathLength = Math.sqrt((diffX * diffX) + (diffY * diffY));
      var node_dst_radius = node_radius;

      // x and y distances from center to outside edge of target node
      offsetX_dst = (diffX * node_dst_radius) / pathLength;
      offsetY_dst = (diffY * node_dst_radius) / pathLength;

      offsetX_src = offsetX_dst;
      offsetY_src = offsetY_dst;

      return "M" + (d.source.x + offsetX_src) + "," + (d.source.y + offsetY_src) + "L" + (d.target.x - offsetX_dst) + "," + (d.target.y - offsetY_dst);
      /*return "M" + d.source.x + "," + d.source.y + ", " + d.target.x + "," + d.target.y;*/
    });
  }
}

makeSVG();
</script>