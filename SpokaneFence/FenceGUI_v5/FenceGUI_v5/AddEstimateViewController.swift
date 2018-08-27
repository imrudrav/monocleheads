//
//  AddEstimateViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 8/1/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class AddEstimateViewController: UIViewController, UITableViewDelegate, UITableViewDataSource  {
    
    var est: Estimate?
    var cus: Customer?
    @IBOutlet var namedata: UILabel?
    @IBOutlet var addressdata: UITextField?
    @IBOutlet var materialdata: UISegmentedControl?
    @IBOutlet var colordata: UISegmentedControl?
    @IBOutlet var styledata: UISegmentedControl?
    @IBOutlet var lineTable: UITableView?
    @IBOutlet var gateTable: UITableView?
    @IBOutlet var extraTable: UITableView?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        lineTable?.dataSource = self
        lineTable?.delegate = self
        lineTable?.register(UITableViewCell.self, forCellReuseIdentifier: "linecell")
        
        
    }

    override func viewDidAppear(_ animated: Bool) {
        est = Estimate(id: 0, cid: (cus?.id)!, eid: 0, date: Date())
        namedata?.text = "New Estimate for \(cus?.fname ?? "Unknown") \(cus?.lname ?? "Customer")"
        addressdata?.text = cus?.address
        updateProperties()
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func updateProperties(){
        est?.address = addressdata?.text
        est?.color = colordata?.titleForSegment(at: (colordata?.selectedSegmentIndex)!)
        est?.style = styledata?.titleForSegment(at: (styledata?.selectedSegmentIndex)!)
        est?.material = materialdata?.titleForSegment(at: (materialdata?.selectedSegmentIndex)!)
    }
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if tableView == self.lineTable {
            //need to create line class
            return (est?.lines.count)!
        }
        if tableView == self.gateTable {
            return (est?.gates.count)!
        }
        if tableView == self.extraTable {
            return (est?.extras.count)!
        }
        else {
            return 0
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
       //figure out which table we are working with
        if tableView == self.lineTable {
            //create cell
            let cell = tableView.dequeueReusableCell(withIdentifier: "linecell") as! linecell
            //pass data
            cell.line = est?.lines[indexPath.item]
            //display data
            cell.textLabel?.text = "Line #\(indexPath.item+1)        Length: \(cell.line?.distance ?? 0)        Number of Sections: \(cell.line?.num_sections ?? 0)        Material Cost: $\(cell.line?.material_cost ?? 0)        Price Per Foot: $\(cell.line?.price_per_foot ?? 0)"
            return cell
        }
        else if tableView == self.gateTable {
            //create cell
            let cell = tableView.dequeueReusableCell(withIdentifier: "gatecell") as! gatecell
            //pass data
            cell.gate = est?.gates[indexPath.item]
            //display data
            cell.textLabel?.text = "Gate #\(indexPath.item+1)        Dimensions: \(cell.gate?.heighth ?? 0)x\(cell.gate?.width ?? 0)ft        Material Cost: $\(cell.gate?.cost ?? 0)"
            return cell
        }
        else {
            //create cell
            let cell = tableView.dequeueReusableCell(withIdentifier: "extracell") as! extracell
            //pass data
            cell.extra = est?.extras[indexPath.item]
            //display data
            cell.textLabel?.text = "Extra #\(indexPath.item+1)        Description: \(cell.extra?.des ?? " ")        Projected Cost: \(cell.extra?.cost ?? 0)"
            return cell
        }
    }
    
    @IBAction func unwindToEstimate(for unwindSegue: UIStoryboardSegue) {
        
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        updateProperties()
        if (segue.identifier == "addgate")
        {
            let addgate = segue.destination as! AddGateViewController
            addgate.gates = (est?.gates)!
            addgate.ngmaterial = est?.material
            addgate.ngcolor = est?.color
            
        }
    }
}
